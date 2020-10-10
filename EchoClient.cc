/**
* @project nanorpc
* @file EchoClient.cc
* @author  S Roychowdhury <sroycode AT gmail DOT com>
* @version 1.0
*
* @section LICENSE
*
* Copyright (c) 2013 S Roychowdhury
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in
* the Software without restriction, including without limitation the rights to
* use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
* the Software, and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
* FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
* COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
* IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
* @section DESCRIPTION
*
* example: echo client
*
*/

#include <iostream>
#include "RpcChannel.hh"
#include "echo.pb.h"

#include "EchoEndpoint.hh"

int main(int argc, char *argv[])
{
	try {
		echo::EchoResponse response;
		echo::EchoRequest request;
		nrpc::RpcChannel rpc_channel(ECHO_ENDPOINT_PORT);

		//stub channel
		echo::EchoService::Stub stub(&rpc_channel);
		
		request.set_message("123456789012345678901234567890123456");
		stub.Echo1(NULL, &request, &response, NULL);
		std::cerr << response.response().c_str() << std::endl;
		
		request.set_message("654321098765432109876543210987654321");
		stub.Echo2(NULL, &request, &response, NULL);
		std::cerr << response.response().c_str() << std::endl;

	} catch (nn::exception& e) {
		std::cerr << "NN EXCEPTION : " << e.what() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "STD EXCEPTION : " << e.what() << std::endl;
	} catch (...) {
		std::cerr << " UNTRAPPED EXCEPTION " << std::endl;
	}
	return 0;
}

