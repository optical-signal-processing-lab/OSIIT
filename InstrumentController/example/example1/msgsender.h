#pragma once
#ifndef MSGTRANS
#define MSGTRANS

#include <WinSock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable:4996)

class MsgSender {
public:
	const char* addr;
	unsigned short port;

	MsgSender(const char* addr, unsigned short port);
	~MsgSender();
	bool sendMsg(char* msg, int len);

private:
	SOCKET m_socket;
	WSADATA wsaData;
	sockaddr_in serAddr;
	int serAddrLen;
};
#endif //!MSGTRANS