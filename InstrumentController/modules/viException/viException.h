#pragma once
#ifndef VIEXCEPTION
#define VIEXCEPTION
#endif // !VIEXCEPTION

#include <stdexcept>
#include <iostream>
#include <visa.h>
#include "error_code.h"

inline std::string VrToString(ViStatus status) {
	char s_str[64] = {};
	sprintf_s(s_str, "Visa Error: 0x%08X\t", static_cast<uint32_t>(status));
	return std::string(s_str)+ErrorCode[static_cast<uint32_t>(status)]+"\t"+ErrorDesp[static_cast<uint32_t>(status)];
}

class ViException :public std::runtime_error {
public:
	ViException(ViStatus status) :std::runtime_error(VrToString(status)), m_vr(status) {}
private:
	const ViStatus m_vr;
};

inline void ThrowIfFailed(ViStatus status) {
	if (status < VI_SUCCESS) {
		throw ViException(status);
	}
}

