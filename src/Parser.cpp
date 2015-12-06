#include <fstream>
#include <iostream>

#include "../include/Parser.h"

Parser::Parser() {}
Parser::~Parser() {}

void Parser::parseGameText(const std::string& outputFile, DWORD address, size_t size)
{
	std::string datas = _undertale.getDatas(address, size);
	std::ofstream file;
	bool prevDebug = false;

	file.open(outputFile, std::ios::out | std::ios::binary | std::ios::trunc);
	for (auto it = datas.begin(); it != datas.end(); ++it) {
		if (prevDebug && it + 1 != datas.end() && *it >= 32 && *(it + 1) >= 32) {
			file << '\n';
		}
		if (*it < 32 || (prevDebug && it + 1 != datas.end() && *(it + 1) < 32)) {
			prevDebug = true;
			file << (int)*it;
		} else {
			prevDebug = false;
			file.write(&(*it), 1);
		}
	}
	file.close();
}