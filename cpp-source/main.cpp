<<<<<<< HEAD
#include <boost\lambda\lambda.hpp>
#include <boost/thread.hpp>
=======
>>>>>>> refs/heads/master
#include <stdio.h>
#include <string>
#include <chrono>
#include <iostream>
#include <thread>
<<<<<<< HEAD

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
	
	// testing the client
	client.send("Hello, World!");

	// create new Postrack class
	Postrack* h = new Postrack();

	// simulate first package arriving
	h->updatePos(10, 10, 10, 0.1, 0.2, 0.1);
	// wait for some time...
	std::this_thread::sleep_for(std::chrono::milliseconds(30));

	// simulate second package arriving
	h->updatePos(30, 2, 10, 0.02, 0.06, 0.1);
	std::this_thread::sleep_for(std::chrono::milliseconds(40));

	h->updatePos(40, 30, 35, 0.05, 0.16, 0.17);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	h->updatePos(-10, -10, -10, 0.2, 0.3, 0.2);
	std::this_thread::sleep_for(std::chrono::milliseconds(60));

	h->updatePos(-50, -20, -30, 0.1, 0.3, 0.1);
	std::this_thread::sleep_for(std::chrono::milliseconds(20));
	
	h->updatePos(-50, -50, -40, 0.15, 0.25, 0.35);
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	
	h->updatePos(32, 15, 16, 0.02, 0.01, 0.1);
=======
#include <windows.h>


#include "Postrack.h"
#include "UDPConroller.h"

void main(){

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
>>>>>>> refs/heads/master

	h->printPath();

	char x;

<<<<<<< HEAD
	// keeps the window open
	std::cin >> x;

	io_service.stop();
=======
	std::cin >> x;
>>>>>>> refs/heads/master
}
