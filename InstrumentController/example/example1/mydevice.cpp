#include "mydevice.h"

int getCharLen(const char* cmd, bool* ask ) {
	int len = 0;
	for (; cmd[len] != '\0'; len++) {
		if (!*ask) {
			if (cmd[len] == '?') {
				*ask = true;
			}
		}
	}
	return len;
}

void color(int a) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

MyDevice::MyDevice(const char* address) :Device(address)
{
	deviceInit(address);
}

MyDevice::~MyDevice() {
	throwIfFailed(viClose(instr));
	throwIfFailed(viClose(defaultRM));
	delete myUDP;
	color(15);
	printf("Disconneted\n");
	color(7);
}

std::string MyDevice::getName() {
	return name;
}

std::string MyDevice::sendCmd(const char* cmd) {
	bool ask = false;
	int len = getCharLen(cmd, &ask);
	std::string result("");
	throwIfFailed(viWrite(instr, reinterpret_cast<ViConstBuf>(cmd), len, &retCount));
	if (ask) {
		do {
			throwIfFailed(viRead(instr, reinterpret_cast<ViPBuf>(buffer), BUFF_LENTH, &retCount));
			result += bufferToString();
		} while (retCount == BUFF_LENTH);
		return result;
	}
	return result;
	
	//status=viQueryf(instr, "%s", "%s", cmd, buffer);
	//可以用这个代替异常
	/*
	if (status < VI_SUCCESS) {
		ViChar desc[1024] = {};
		viStatusDesc(instr, status, desc);
		printf("%s", desc);
		return " ";
	}
	*/
}

void MyDevice::InteractiveMode()
{
	char cmd[256];
	while (1) {
		try {
			color(10);
			printf("%s >> ", name.c_str());
			color(7);
			std::cin.getline(cmd,256);
			if (cmd[0] == 'q') {
				char q[5] = "quit";
				myUDP->sendMsg(q, 5);
				break;
			}
			if (cmd[0] == 'v') {
				auto startwl = sendCmd("STARTWL?");
				auto stopwl = sendCmd("STOPWL?");
				auto tra = sendCmd("TRA?");
				std::string info = startwl + ";" + stopwl + ";" + tra;
				myUDP->sendMsg((char*)info.c_str(), info.length());
			}
			else if (cmd[0] == 'x') {
				auto rl = sendCmd("RL?;");
				auto lg = sendCmd("LG?;");
				std::string info = rl + ";" + lg;
				myUDP->sendMsg((char*)info.c_str(), info.length());
			}
			else {
				color(11);
				auto res = sendCmd((const char*)cmd);
				if (!res.empty()) {
					std::cout << res << std::endl;
				}
			}
		}
		catch (ViException& e) {
			color(12);
			std::cout << sendCmd("ERR?\n") << std::endl;
			std::cout << e.what() << std::endl;
			color(7);
		}
	}
}

void MyDevice::deviceInit(const char* address)
{
	throwIfFailed(viOpenDefaultRM(&defaultRM));
	throwIfFailed(viOpen(defaultRM, address, VI_NULL, VI_NULL, &instr));
	throwIfFailed(viSetAttribute(instr, VI_ATTR_TMO_VALUE, 5000));
	throwIfFailed(viWrite(instr, reinterpret_cast<ViConstBuf>("ID?\n"), 4, &retCount));
	throwIfFailed(viRead(instr, reinterpret_cast<ViPBuf>(buffer), BUFF_LENTH, &retCount));

	myUDP = new MsgSender("127.0.0.1", 8888);
	name = bufferToString();
}

std::string MyDevice::bufferToString()
{
	if (retCount != 0) {
		char* result = new char[retCount + 1];
		if (retCount == BUFF_LENTH) {
			strncpy(result, buffer, retCount);
			result[retCount] = '\0';
			std::string r(result);
			delete[] result;
			return r;
		}
		else {
			strncpy(result, buffer, retCount - 1);
			result[retCount - 1] = '\0';
			std::string r(result);
			delete[] result;
			return r;
		}
	}
	return std::string("");
}