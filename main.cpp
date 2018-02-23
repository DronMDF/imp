// Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "AsioService.h"
#include "Server.h"

using namespace std;

int main(int, char **argv)
{
	auto service = make_shared<AsioService>();
	Server server(service->createAcceptor(atoi(argv[1])));
	service->run();
}
