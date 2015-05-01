#pragma once

#include <string>
#include <map>
#include "FileClass.h"

class ToppingClass
{
public:
	ToppingClass();
	~ToppingClass();

	bool Initialize();
	void printAll();
	double getPrice(int ID);
	int numToppings();
	std::string getToppingInfo(int ID);

private:
	std::map<std::string, double>m_Toppings;
	std::map<int, std::string>toppingInfo;
	double *elementValue;
	int numElements;
};

