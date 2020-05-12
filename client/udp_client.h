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
		udp_client(std::string server_ip,int server_port);//client要监听的server的ip和端口号,为构造函数
		void init_client();//初始化client
		void recv_data(std::string &out_string);//发送数据
		void send_data(const std::string &in_string);//接收数据
		~udp_client();//为析构函数
	private:
		int sock;//
		struct sockaddr_in server;//定义一个server结构体
};

