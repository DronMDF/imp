// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "AsioService.h"
#include "AsioAcceptor.h"

using namespace std;

shared_ptr<AsioAcceptor> AsioService::createAcceptor(in_port_t port)
{
	return make_shared<AsioAcceptor>(
		make_shared<asio::ip::tcp::acceptor>(
			service,
			asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)
		)
	);
}

void AsioService::run()
{
	service.run();
}
