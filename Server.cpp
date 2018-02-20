// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Server.h"
#include <functional>
#include "Session.h"

using namespace std;

Server::Server(asio::io_service *service, in_port_t port)
	: acceptor(make_shared<AsioAcceptor>(service, port))
{
	do_accept();
}

void Server::do_accept()
{
	acceptor->accept(bind(&Server::handle_accept, this, placeholders::_1, placeholders::_2));
}

void Server::handle_accept(error_code ec, const shared_ptr<asio::ip::tcp::socket> &socket)
{
	if (!ec) {
		make_shared<Session>(socket)->start();
	}

	do_accept();
}
