// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "AsioAcceptor.h"

using namespace std;

AsioAcceptor::AsioAcceptor(asio::io_service *service, in_port_t port)
	: acceptor(*service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
{
}

void AsioAcceptor::accept(
	const function<void(error_code, const shared_ptr<asio::ip::tcp::socket> &)> &handler
)
{
	const auto socket = make_shared<asio::ip::tcp::socket>(acceptor.get_io_service());
	acceptor.async_accept(*socket, bind(handler, placeholders::_1, socket));
}
