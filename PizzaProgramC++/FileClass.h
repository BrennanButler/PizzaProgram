#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>

class FileClass
{
public:
	FileClass();
	~FileClass();

	//Example usage:
	//
	//	LoadFile("food.txt", FoodNames, FoodValue);
	bool LoadFile(char *fileName, std::map<std::string, double> &returnedValue, int &num);
};

