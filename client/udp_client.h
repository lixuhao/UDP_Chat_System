#pragma  once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 1024

class udp_client{
	public:
		udp_client(std::string server_ip,int server_port);
		void init_client();
		void recv_data(std::string &out_string);
		void send_data(const std::string &in_string);
		~udp_client();
	private:
		int sock;
		struct sockaddr_in server;
};

