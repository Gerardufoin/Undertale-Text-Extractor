#include <fstream>
#include <iostream>

#include "../include/Parser.h"

Parser::Parser()
{
	// Remove character face
	_modifiers.push_back(std::make_pair(std::regex(R"(\\E\d)"), ""));
	// Remove text modifier
	_modifiers.push_back(std::make_pair(std::regex(R"(\\Y|\\W)"), ""));
	_modifiers.push_back(std::make_pair(std::regex(R"(\/%{2,}[\x00-\x1F][\x00-\xFF.][\x00-\x1F]{3})"), "\n\n"));
	_modifiers.push_back(std::make_pair(std::regex(R"(\/?%{0,2}[\x00-\x1F][\x00-\xFF.][\x00-\x1F]{3}|&)"), "\n"));
	_modifiers.push_back(std::make_pair(std::regex(R"(\^\d|\\[A-z]\w?)"), ""));
}

Parser::~Parser() {}

void Parser::parseGameText(const std::string& outputFile, DWORD address, size_t size)
{
	std::string datas = _undertale.getDatas(address, size);

	for (auto it = _modifiers.begin(); it != _modifiers.end(); ++it) {
		std::string result;
		std::regex_replace(std::back_inserter(result), datas.begin(), datas.end(), (*it).first, (*it).second);
		datas = result;
	}

	std::ofstream file;
	file.open(outputFile, std::ios::out | std::ios::binary | std::ios::trunc);
	file.write(datas.c_str(), datas.size());
	file.close();
}