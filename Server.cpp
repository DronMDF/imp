// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Server.h"
#include <functional>
#include "Session.h"

using namespace std;

Server::Server(asio::io_service *service, in_port_t port)
	: acceptor(*service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), socket(*service)
{
	do_accept();
}

void Server::do_accept()
{
	acceptor.async_accept(socket, bind(&Server::handle_accept, this, placeholders::_1));
}

void Server::handle_accept(error_code ec)
{
	if (!ec) {
		make_shared<Session>(move(socket))->start();
	}

	do_accept();
}
