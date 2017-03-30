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

	// create io_services for network communication
	boost::asio::io_service io_service;

	// add the services to a second thread
	boost::thread bt(boost::bind(&boost::asio::io_service::run, &io_service));

	// create UDP Client on port 13
	UDPClient client(io_service, "localhost", "13");
	
	// create UDP Server
	UDPController server(io_service);

	// start Network communication services
	io_service.run();

	// wait
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	
	// only testing the client
	client.send("Hello, World!");

	// create new Postrack class
	Postrack* h = new Postrack();

	// simulate first package arriving
	h->updatePos(10);

	// wait for some time...
	std::this_thread::sleep_for(std::chrono::milliseconds(30));

	// simulate second package arriving
	h->updatePos(300);
	std::this_thread::sleep_for(std::chrono::milliseconds(40));

	h->updatePos(40);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	h->updatePos(-100);
	std::this_thread::sleep_for(std::chrono::microseconds(600));
	h->updatePos(-50);

	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	h->updatePos(-500);

	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	h->updatePos(320);

	h->printPath();

	char x;

	// keeps te window open till you press any key and enter
	std::cin >> x;

	io_service.stop();
}
