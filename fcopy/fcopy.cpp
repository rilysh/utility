// fcopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <Windows.h>

bool is_exists(const char *file)
{
	auto exists = std::ifstream(file);
	if (exists)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool copy_file(const char *file, const char *toCopy, std::size_t bufferSize = 1048576)
{
	if (is_exists(file) == false)
	{
		std::cout << "File not exists" << std::endl;
		return EXIT_SUCCESS;
	}

	std::ifstream is(file, std::ios::binary);
	std::ofstream os(toCopy, std::ios::binary);
	std::pair<char *, std::ptrdiff_t> buffer;
	buffer = std::get_temporary_buffer<char>(bufferSize);

	while (is.good())
	{
		is.read(buffer.first, buffer.second);
		os.write(buffer.first, is.gcount());
	}

	std::return_temporary_buffer(buffer.first);
	if (os.fail()) return false;
	if (is.eof()) return true;
}

int _tmain(int argc, const char *argv[])
{
	if (argc < 3)
	{
		std::cout << "File path and desctination must required" << std::endl;
		return EXIT_FAILURE;
	}
	auto timeStart = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	bool result = copy_file(argv[1], argv[2]);
	auto timeNow = std::chrono::high_resolution_clock::now();
	auto diff = timeNow - timeStart;
	auto secs = std::chrono::duration_cast<std::chrono::duration<float>>(diff);

	if (result == true)
	{
		std::cout << "Copy successfull, took " << secs.count() << " seconds" << std::endl;
		return EXIT_SUCCESS;
	}
	else
	{
		std::cout << "An error occurred in operation, debug code: " << GetLastError() << std::endl;
		return EXIT_FAILURE;
	}
}
