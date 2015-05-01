#include "ToppingClass.h"


ToppingClass::ToppingClass()
{
}


ToppingClass::~ToppingClass()
{
	if (elementValue)
	{
		delete elementValue;
		elementValue = nullptr;
	}
}

bool ToppingClass::Initialize()
{
	int num = 0;

	FileClass file;
	file.LoadFile("Toppings.txt", m_Toppings, num);

	//std::cout << "Number of elements : " << num << "\n\n";

	elementValue = new double[num];
	numElements = num;
	num = 0;

	for (std::map<std::string, double>::iterator i = m_Toppings.begin(); i != m_Toppings.end(); ++i)
	{
		elementValue[num] = i->second;
		toppingInfo[num] = i->first;
		num++;
	}
	return true;
}

int ToppingClass::numToppings()
{
	return numElements;
}

double ToppingClass::getPrice(int ID)
{
	return elementValue[ID];
}

std::string ToppingClass::getToppingInfo(int ID)
{
	return toppingInfo.find(ID)->second;
}

void ToppingClass::printAll()
{
	int elementNumber = 0;

	for (std::map <std::string, double>::iterator i = m_Toppings.begin(); i != m_Toppings.end(); ++i)
	{
		std::cout << elementNumber << " " << i->first << " " << i->second << std::endl;
		elementNumber++;
	}
}