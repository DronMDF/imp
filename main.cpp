#include <functional>
#include <memory>
#include <asio.hpp>

using namespace std;

class Session : public enable_shared_from_this<Session>
{
public:
	Session(asio::ip::tcp::socket socket)
		: socket(move(socket))
	{
	}

	void start()
	{
		do_read();
	}

private:
	void do_read()
	{
		socket.async_read_some(
			asio::buffer(data_, max_length),
			bind(&Session::handle_read, shared_from_this(), placeholders::_1, placeholders::_2)
		);
	}

	void handle_read(error_code ec, size_t length)
	{
		if (!ec) {
			do_write(length);
		}
	}

	void do_write(size_t length)
	{
		auto self(shared_from_this());
		asio::async_write(
			socket,
			asio::buffer(data_, length),
			bind(&Session::handle_write, shared_from_this(), placeholders::_1, placeholders::_2)
		);
	}

	void handle_write(error_code ec, size_t)
	{
		if (!ec) {
			do_read();
		}
	}

	asio::ip::tcp::socket socket;
	enum { max_length = 1024 };
	char data_[max_length];
};

class Server {
public:
	Server(asio::io_service &service, in_port_t port)
		: acceptor(service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), socket(service)
	{
		do_accept();
	}

private:
	void do_accept()
	{
		acceptor.async_accept(socket, bind(&Server::handle_accept, this, placeholders::_1));
	}

	void handle_accept(error_code ec)
	{
		if (!ec) {
			make_shared<Session>(move(socket))->start();
		}

		do_accept();
	}

	asio::ip::tcp::acceptor acceptor;
	asio::ip::tcp::socket socket;
};

int main(int, char **argv)
{
	asio::io_service service;
	Server server(service, atoi(argv[1]));
	service.run();
}
