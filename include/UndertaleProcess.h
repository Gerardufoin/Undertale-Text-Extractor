#pragma once

#include <string>
#include <windows.h>

class UndertaleProcess
{
public:
	UndertaleProcess();
	~UndertaleProcess();

	std::string getDatas(DWORD address, size_t size);

private:
	HANDLE _handler;
};