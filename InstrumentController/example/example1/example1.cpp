#include "example1.h"

int main()
{
	try {
		MyDevice& HP70952B = MyDevice::getMyDevice("GPIB0::23::INSTR");
		HP70952B.InteractiveMode();
	}
	catch (ViException& e1) {
		std::cout << e1.what() << std::endl;
	}
	
	return 0;
}
