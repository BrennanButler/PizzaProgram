#include "TableClass.h"
#include <ctype.h>

TableClass::TableClass()
{
}


TableClass::~TableClass()
{
}

int TableClass::SetupTable()
{
	int input = 0;
	std::cout << "Please enter a number between 1 and 25 to choose a table number\n";

	while (input > 25 || input < 1)
	{
		std::cin >> input;

		if (input > 25 || input < 1 || std::cin.fail())
		{
			std::cout << "Please enter a number between 1 and 25\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	

	return input;
}