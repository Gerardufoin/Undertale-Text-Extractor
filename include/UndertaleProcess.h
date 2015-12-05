#pragma once

#include <vector>
#include <windows.h>

class UndertaleProcess
{
public:
	UndertaleProcess();
	~UndertaleProcess();

	std::vector<char> getDatas(DWORD address, size_t size);

private:
	HANDLE _handler;
};