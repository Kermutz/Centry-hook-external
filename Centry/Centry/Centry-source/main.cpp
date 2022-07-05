#include "memory.h"

#include <thread>
namespace offsets
{
	constexpr auto localPlayer = 0xDBF4CC;
	constexpr auto flags = 0x104;
	constexpr auto forceJump = 0x52858A8;
}


int main()
{
	auto mem = Memory("csgo.exe");
	std::cout << "Loading Centry to process id:" << mem.GetProcessId() << std::endl;

	const auto client = mem.GetModuleAdress("client.dll");
	std::cout << "client ->" << "0x" << std::hex << client << std::dec << std::endl;

	while (true)


	{

		const auto localPlayer = mem.Read<uintptr_t>(client + offsets::localPlayer);

		if (localPlayer)
		{
			const auto onGround = mem.Read<bool>(localPlayer + offsets::flags);

			if (GetAsyncKeyState(VK_SPACE) && onGround & (1 << 0))
				mem.Write<BYTE>(client + offsets::forceJump, 6);
				
			

			
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}



