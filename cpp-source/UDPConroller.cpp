#include "UDPConroller.h"

#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

using namespace std;

UDPController::UDPController(boost::asio::io_service& io_service) : socket_(io_service, udp::endpoint(udp::v4(), 13))
{
	start_receive();
}


UDPController::~UDPController()
{
}

void UDPController::start_receive(){
	socket_.async_receive_from(
		boost::asio::buffer(recv_buffer_), remote_endpoint_,
		boost::bind(&UDPController::handle_receive, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void UDPController::handle_receive(const boost::system::error_code& error,
	std::size_t bytes_transferred){
	if (!error || error == boost::asio::error::message_size)
	{
		boost::shared_ptr<std::string> message(
			new std::string(make_daytime_string()));

		socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
			boost::bind(&UDPController::handle_send, this, message,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));

		std::copy(this->recv_buffer_.begin(), this->recv_buffer_.begin() + bytes_transferred, std::back_inserter(this->data));

		std::cout << this->data;

		start_receive();
	}
}

void UDPController::handle_send(boost::shared_ptr<std::string>,
	const boost::system::error_code&,
	std::size_t){}

	
std::string UDPController::make_daytime_string()
{
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	return std::ctime(&now_c);
}