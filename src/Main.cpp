#include <iostream>

#include "../include/Parser.h"

int main(int argc, char *argv[])
{
	if (argc < 4) {
		std::cout << "Usage: output_file start_address read_size" << std::endl;
		return (0);
	}

	Parser parser;
	parser.parseGameText(argv[1], std::stoul(argv[2], nullptr, 16), std::stoi(argv[3]));

	return (0);
}