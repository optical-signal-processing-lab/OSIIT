// Device.h: 目标的头文件。
#pragma once
#ifndef DEVICE
#define DEVICE
#endif // !DEVICE

#include <string>

class Device {
public:
	Device(const char* address);
	virtual ~Device() = default;
	virtual void deviceInit(const char* address) = 0;
	virtual std::string getName() = 0;
	virtual std::string command(const char* cmd) = 0;
};


