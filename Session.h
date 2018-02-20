// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <asio.hpp>

class Session : public std::enable_shared_from_this<Session>
{
public:
	explicit Session(asio::ip::tcp::socket socket);

	void start();

private:
	void do_read();
	void handle_read(std::error_code ec, size_t length);
	void do_write(size_t length);
	void handle_write(std::error_code ec, size_t);

	asio::ip::tcp::socket socket;
	std::vector<uint8_t> data;
};

