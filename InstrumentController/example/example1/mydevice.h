#pragma once
#ifndef EXAMPLE_MYDEVICE
#define EXAMPLE_MYDEVICE

#include <device.h>
#include <viexception.h>
#include <string>
#include <visa.h>
#include <Windows.h>


#define BUFF_LENTH 1024
class MyDevice :public Device {
public:
	std::string getName();
	std::string sendCmd(const char* cmd);
	void InteractiveMode();
	static MyDevice& getMyDevice(const char* address) {
		static MyDevice myDevice(address);
		return myDevice;
	}

private:
	MyDevice(const char* address);
	~MyDevice();
	void deviceInit(const char* address);
	std::string bufferToString();

	std::string name;
	std::string address;
	ViStatus status = 0;
	ViSession defaultRM = 0, instr = 0;
	ViUInt32 retCount = 0;
	ViChar buffer[BUFF_LENTH] = { 0 };
};
#endif // !EXAMPLE_MYDEVICE