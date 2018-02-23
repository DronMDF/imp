// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <asio.hpp>
#include "AsioAcceptor.h"

class Server {
public:
	explicit Server(const std::shared_ptr<AsioAcceptor> &acceptor);

private:
	void do_accept();
	void handle_accept(
		std::error_code ec,
		const std::shared_ptr<asio::ip::tcp::socket> &socket
	);

	const std::shared_ptr<AsioAcceptor> acceptor;
};
