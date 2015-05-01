#include "DrinkClass.h"

DrinkClass::DrinkClass()
{
}

DrinkClass::~DrinkClass()
{
	if (elementValue)
	{
		delete elementValue;
		elementValue = nullptr;
	}
}

bool DrinkClass::Initialize()
{
	int num = 0;

	FileClass file;
	file.LoadFile("Drinks.txt", m_Drinks, num);

	std::cout << "Number of elements : " << num << "\n\n";

	elementValue = new double[num];
	numElements = num;
	num = 0;

	for (std::map<std::string, double>::iterator i = m_Drinks.begin(); i != m_Drinks.end(); ++i)
	{
		elementValue[num] = i->second;
		drinkInfo[num] = i->first;
		num++;
	}

	return true;
}

int DrinkClass::numDrinks()
{
	return numElements;
}

double DrinkClass::getPrice(int ID)
{
	return elementValue[ID];
}

std::string DrinkClass::getDrinkInfo(int ID)
{
	return drinkInfo.find(ID)->second;
}

void DrinkClass::printAll()
{
	int elementNumber = 0;

	for (std::map <std::string, double>::iterator i = m_Drinks.begin(); i != m_Drinks.end(); ++i)
	{
		std::cout << elementNumber << " " << i->first << " " << i->second << std::endl;
		elementNumber++;
	}
}