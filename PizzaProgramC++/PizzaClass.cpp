#include "PizzaClass.h"


PizzaClass::PizzaClass()
{
}


PizzaClass::~PizzaClass()
{
	if (elementValue)
	{
		delete elementValue;
		elementValue = nullptr;
	}
}

bool PizzaClass::Initialize()
{
	int num = 0;
	FileClass file;
	file.LoadFile("Pizza.txt", m_Pizzas, num);

	//std::cout << "Number of elements : " << num << "\n\n";

	elementValue = new double[num];

	totalElements = num;
	num = 0;

	for (std::map<std::string, double>::iterator i = m_Pizzas.begin(); i != m_Pizzas.end(); ++i)
	{
		elementValue[num] = i->second;
		pizzaInfo[num] = i->first;
		num++;
	}
	return true;
}

int PizzaClass::numPizzas()
{
	return totalElements;
}

double PizzaClass::getPrice(int ID)
{
	return elementValue[ID];
}

std::string PizzaClass::getPizzaInfo(int ID)
{
	return pizzaInfo.find(ID)->second;
}

void PizzaClass::printAll()
{
	int elementNumber = 0;

	for (std::map <std::string, double>::iterator i = m_Pizzas.begin(); i != m_Pizzas.end(); ++i)
	{
		std::cout << elementNumber << " " << i->first << " " << i->second << std::endl;
		elementNumber++;
	}
}
