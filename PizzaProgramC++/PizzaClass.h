#pragma once

#include <map>
#include "FileClass.h"

class PizzaClass
{
public:

	PizzaClass();
	~PizzaClass();

	bool Initialize();
	std::string getPizzaInfo(int ID);
	void printAll();
	double getPrice(int ID);

	int numPizzas();

	private:
		std::map<std::string, double>m_Pizzas;
		std::map<int, std::string>pizzaInfo;
		double *elementValue;
		int totalElements;
};

