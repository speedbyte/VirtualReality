#include <boost\lambda\lambda.hpp>
#include <boost/thread.hpp>
#include <stdio.h>
#include <string>
#include <chrono>
#include <iostream>
#include <thread>

#include <iterator>
#include <algorithm>


#include "Postrack.h"
#include "UDPConroller.h"
#include "UDPClient.h"
#include "quadcopter_dynamics.h"
#include <windows.h>

void main(){

	boost::asio::io_service io_service;

	boost::thread bt(boost::bind(&boost::asio::io_service::run, &io_service));

	UDPClient client(io_service, "localhost", "13");
	UDPController server(io_service);

	io_service.run();

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	client.send("Hello, World!");

	Postrack* h = new Postrack();

	h->updatePos(10);
	std::this_thread::sleep_for(std::chrono::microseconds(10));
	h->updatePos(300);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	h->updatePos(40);

	std::this_thread::sleep_for(std::chrono::milliseconds(2));

	h->updatePos(-100);
	std::this_thread::sleep_for(std::chrono::microseconds(100));
	h->updatePos(-50);

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	h->updatePos(-500);
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	h->updatePos(320);

	h->printPath();

	char x;

	std::cin >> x;

	io_service.stop();
}
