// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <functional>
#include <memory>
#include <asio.hpp>

class AsioAcceptor {
public:
	AsioAcceptor(asio::io_service *service, in_port_t port);

	void accept(
		const std::function<
			void(std::error_code, const std::shared_ptr<asio::ip::tcp::socket> &)
		> &handler
	);

private:
	asio::ip::tcp::acceptor acceptor;
};
