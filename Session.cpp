// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Session.h"
#include <functional>

using namespace std;

Session::Session(const shared_ptr<asio::ip::tcp::socket> &socket)
	: socket(socket), data(1024)
{
}

void Session::start()
{
	do_read();
}

void Session::do_read()
{
	socket->async_read_some(
		asio::buffer(&data[0], data.size()),
		bind(&Session::handle_read, shared_from_this(), placeholders::_1, placeholders::_2)
	);
}

void Session::handle_read(error_code ec, size_t length)
{
	if (!ec) {
		do_write(length);
	}
}

void Session::do_write(size_t length)
{
	asio::async_write(
		*socket,
		asio::buffer(&data[0], length),
		bind(&Session::handle_write, shared_from_this(), placeholders::_1, placeholders::_2)
	);
}

void Session::handle_write(error_code ec, size_t)
{
	if (!ec) {
		do_read();
	}
}
