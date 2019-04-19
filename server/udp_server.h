#pragma once

#include <iostream>
#include <string>
#include <map>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "data_pool.h"

#define SIZE 1024

class udp_server{
	public:
		udp_server(int _port);
		void init_server();
		void recv_data(std::string &out_string);
		void broadcast();
		~udp_server();

	private:
		void send_data(const std::string &in_string,const struct sockaddr_in &peer);

	private:
		int sock;
		int port;
		data_pool pool;
		std::map<uint32_t, struct sockaddr_in> online;
};














