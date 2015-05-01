#pragma once

#include <string>
#include <map>
#include <iostream>
#include "FileClass.h"

class DrinkClass
{
public:
	DrinkClass();
	~DrinkClass();

	bool Initialize();
	std::string getDrinkInfo(int ID);
	void printAll();
	double getPrice(int ID);
	int numDrinks();

private:
	std::map<std::string, double>m_Drinks;
	std::map<int, std::string>drinkInfo;
	double *elementValue;
	int numElements;
};

