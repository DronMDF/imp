// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <asio.hpp>

class Server {
public:
	Server(asio::io_service *service, in_port_t port);

private:
	void do_accept();
	void handle_accept(std::error_code ec);

	asio::ip::tcp::acceptor acceptor;
	asio::ip::tcp::socket socket;
};
