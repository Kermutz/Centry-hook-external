#include "memory.h"

int main()
{
	auto mem = Memory("csgo.exe");
	std::cout << "Loading Centry to process id:" << mem.GetProcessId() << std::endl;

	while (true)
	{

	}
}

