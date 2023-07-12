#include "example1.h"

int main()
{
	try {
		MyDevice& HP70952B = MyDevice::getMyDevice("GPIB0::23::INSTR");
		try {
			std::cout << HP70952B.getName() << std::endl;
			std::cout << HP70952B.sendCmd("TRA?\n") << std::endl;
		}
		catch (ViException& e) {
			std::cout << HP70952B.sendCmd("ERR?\n") << std::endl;
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << HP70952B.sendCmd("A?\n") << std::endl;
		}
		catch (ViException& e2) {
			std::cout << HP70952B.sendCmd("ERR?\n") << std::endl;
			std::cout << e2.what() << std::endl;
		}
	}
	catch (ViException& e1) {
		std::cout << e1.what() << std::endl;
	}
	
	return 0;
}
