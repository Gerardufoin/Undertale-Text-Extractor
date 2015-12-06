#pragma once

#include <string>
#include <vector>
#include <regex>
#include <utility>
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
	std::vector< std::pair< std::regex, std::string > > _modifiers;
};