#include <fstream>
#include <vector>

#include "../include/Parser.h"

Parser::Parser() {}
Parser::~Parser() {}

void Parser::parseGameText(const std::string& outputFile, DWORD address, size_t size)
{
	std::vector<char> datas = _undertale.getDatas(address, size);
	std::ofstream file;

	file.open(outputFile, std::ios::out | std::ios::binary);
	file.write(&datas[0], datas.size());
	file.close();
}