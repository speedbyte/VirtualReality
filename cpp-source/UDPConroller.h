#pragma once
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
using boost::asio::ip::udp;

class UDPController
{
public:
	UDPController(boost::asio::io_service& io_service);

	~UDPController();


	void start_receive();

private:

	

	void handle_receive(const boost::system::error_code& error,
		std::size_t /*bytes_transferred*/);

	void handle_send(boost::shared_ptr<std::string> /*message*/,
		const boost::system::error_code& /*error*/,
		std::size_t /*bytes_transferred*/);

	std::string make_daytime_string();

	udp::socket socket_;
	udp::endpoint remote_endpoint_;
	boost::array<char, 1> recv_buffer_;

	std::string data;

};

