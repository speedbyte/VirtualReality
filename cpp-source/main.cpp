#include <stdio.h>
#include <string>
#include <chrono>
#include <iostream>
#include <thread>
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

	h->printPath();

	char x;

	std::cin >> x;
}
