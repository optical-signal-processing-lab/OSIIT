#include "mydevice.h"

int getCharLen(const char* cmd) {
	int len = 0;
	for (; cmd[len] != '\0'; len++) {}
	return len;
}

MyDevice::MyDevice(const char* address) :Device(address)
{
	deviceInit(address);
}

MyDevice::~MyDevice() {
	printf("in ~MyDevice\n");
	throwIfFailed(viClose(instr));
	throwIfFailed(viClose(defaultRM));
	printf("~MyDevice OK\n");
}

std::string MyDevice::getName() {
	return name;
}

std::string MyDevice::sendCmd(const char* cmd) {
	int len = getCharLen(cmd);
	std::string result("");
	throwIfFailed(viWrite(instr, reinterpret_cast<ViConstBuf>(cmd), len, &retCount));
	do {
		throwIfFailed(viRead(instr, reinterpret_cast<ViPBuf>(buffer), 256, &retCount));
		result += bufferToString();
	} while (retCount == 256);
	return result;
}

void MyDevice::deviceInit(const char* address)
{
	throwIfFailed(viOpenDefaultRM(&defaultRM));
	throwIfFailed(viOpen(defaultRM, address, VI_NULL, VI_NULL, &instr));
	throwIfFailed(viSetAttribute(instr, VI_ATTR_TMO_VALUE, 5000));
	throwIfFailed(viWrite(instr, reinterpret_cast<ViConstBuf>("ID?\n"), 4, &retCount));
	throwIfFailed(viRead(instr, reinterpret_cast<ViPBuf>(buffer), 256, &retCount));

	name = bufferToString();
}

std::string MyDevice::bufferToString()
{
	if (retCount != 0) {
		char* result = new char[retCount];
		strncpy(result, buffer, retCount - 1);
		result[retCount - 1] = '\0';
		std::string r(result);
		delete[] result;
		return r;
	}
	return std::string("");
}