#include <iostream>

#include "../include/UndertaleProcess.h"

UndertaleProcess::UndertaleProcess()
{
	DWORD pid;
	HWND undertale;

	if ((undertale = FindWindow(NULL, L"UNDERTALE")) == NULL) {
		std::cerr << "Undertale window cannot be found." << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!GetWindowThreadProcessId(undertale, &pid)) {
		std::cerr << "Unable to retrieve the process id." << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((_handler = OpenProcess(PROCESS_VM_READ, 0, pid)) == NULL) {
		std::cerr << "Unable to open the process." << std::endl;
		exit(EXIT_FAILURE);
	}
}

UndertaleProcess::~UndertaleProcess() {}

std::string UndertaleProcess::getDatas(DWORD address, size_t size) {
	char* datas = new char[size];
	SIZE_T read;

	ReadProcessMemory(_handler, (void*)address, datas, size, &read);
	std::string ret(datas, datas + read);
	delete[] datas;

	return ret;
}
