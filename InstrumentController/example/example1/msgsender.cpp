#include "msgsender.h"

void msgColor(int a) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

MsgSender::MsgSender(const char* addr, unsigned short port):addr(addr),port(port) {
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		msgColor(12);
		std::cout << "WSAStart Failed\n";
		msgColor(7);
		return;
	}
	
	m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (m_socket == INVALID_SOCKET) {
		msgColor(12);
		std::cout << "INVALID_SOCKET\n";
		msgColor(7);
		return;
	}

	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(port);
	serAddrLen = sizeof(serAddr);
	serAddr.sin_addr.S_un.S_addr = inet_addr(addr);
}

MsgSender::~MsgSender() {
	closesocket(m_socket);
	WSACleanup();
}

bool MsgSender::sendMsg(char* msg, int len) {
	int sendlen = sendto(m_socket, msg, len, 0, (sockaddr*)&serAddr, serAddrLen);
	if (sendlen > 0) {
		msgColor(14);
		printf("[UDP]\tSended %d bytes\n", sendlen);
		msgColor(7);
		return true;
	}
	return false;
}