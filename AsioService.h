// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <asio.hpp>

class AsioAcceptor;

class AsioService final {
public:
	std::shared_ptr<AsioAcceptor> createAcceptor(in_port_t port);
	void run();

private:
	asio::io_service service;
};
