#pragma once
#include <Windows.h>
#include <iostream>

class Memory
{
private:
	DWORD id = 0;
	HANDLE process = NULL;

public:
	Memory(const char* processName);
	~Memory();

	DWORD GetProcessId();
	HANDLE GetProcessHandle();

	uintptr_t GetModuleAdress(const char* moduleName);
	template <typename T>

	T Read(uintptr_t adress)
	{
		T value;
		ReadProcessmemory(this->process, (LPCVOID)adress, &value, sizeof(T), NULL);

	};

};