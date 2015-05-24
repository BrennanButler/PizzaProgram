#include "ToppingClass.h"


ToppingClass::ToppingClass()
	: elementValue(NULL)
{
}


ToppingClass::~ToppingClass()
{
	// If elementValue has been used, free its memory
	if (elementValue)
	{
		delete elementValue;
		elementValue = nullptr;
	}
}

bool ToppingClass::Initialize()
{
	int num = 0;

	// New file class
	FileClass file;

	// Load the drinks file, parse the contents into the m_Drinks map container 
	// and add up the total parsed elements and assign it to num
	if (!file.LoadFile("Toppings.txt", m_Toppings, num))
		return false;


	// Now we know the total amount of elements we can assign the right amount of memory cells to the elementValue variable
	elementValue = new double[num];

	// Assign the global numElements variable to num for future use
	numElements = num;

	// We're going to use this for another purpose, lets make sure we don't have existing values
	num = 0;

	// Loop through all the elements we parsed within the file
	for (std::map<std::string, double>::iterator i = m_Toppings.begin(); i != m_Toppings.end(); ++i)
	{
		// The map is structured as follows:
		// std::string -> first 
		// double	   -> second
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
	// Return the elements value for the given ID
	return elementValue[ID];
}

std::string ToppingClass::getToppingInfo(int ID)
{
	// Search through the map and find its name
	return toppingInfo.find(ID)->second;
}

void ToppingClass::printAll()
{
	int elementNumber = 0;
	// Loop through all the elements and print out the contents.
	for (std::map <std::string, double>::iterator i = m_Toppings.begin(); i != m_Toppings.end(); ++i)
	{
		std::cout << elementNumber << " " << i->first << " " << i->second << std::endl;
		elementNumber++;
	}
}