#pragma once

#include <string>

//Author: Furkan Celik Date: 22.12.2018

namespace Lazarus {

	class FileUtils { //Used class to overcome some complications came by using free functions
	public:
		static std::string readFile(const char* filepath) { //reads file in given filepath and returns it as a string. Used C type file input since it is a lot faster than c++ implementation
			FILE* file = fopen(filepath, "rt"); //opens text file with read only
			fseek(file, 0, SEEK_END); //goes to end of file
			unsigned int length = ftell(file); //recording length of file
			char* data = new char[length + 1]; //creating char array size of length + 1. + 1 is for end stamp
			memset(data, 0, length + 1); //setting all elements of char array to 0 since our read file function may keep some of them blank
			fseek(file, 0, SEEK_SET); //returns to beginning of file
			fread(data, 1, length, file); //reads file of length to data array
			fclose(file); //closes file. Important part is instead of c++, c won't close file automaticly since it is not an object. We should close it to prevent possible errors when we wanted to re-open file

			std::string result(data); //converting data array to string since we want to return content as a string
			delete[] data; //deleting data array since it is kept in dynamic memory and won't be destructed until we delete it. This will free up a lot of memory

			return result;
		}
	};

}