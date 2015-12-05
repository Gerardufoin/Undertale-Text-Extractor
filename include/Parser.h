#pragma once

#include <string>
#include <windows.h>

#include "../include/UndertaleProcess.h"

class Parser
{
public:
	Parser();
	~Parser();

	void parseGameText(const std::string& outputFile, DWORD address, size_t size);

private:
	UndertaleProcess _undertale;
};