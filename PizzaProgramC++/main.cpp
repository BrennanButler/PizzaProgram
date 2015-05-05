#include <stdlib.h>

#include "TableClass.h"
#include "FADClass.h"


void doPizza(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders);
void doDrink(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders);
void doTopping(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders);
void doSize(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders);

void doPizza(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders)
{
	int input = -1;
	system("cls");
	std::cout << "Please choose a Pizza\n";
	foodAndDrink.ShowMenu(PIZZA);
	while (input > foodAndDrink.numElements(PIZZA) || input < 0)
	{

		std::cin >> input;

		if (input > foodAndDrink.numElements(PIZZA) || input < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}

	std::cout << "You have chosen " << foodAndDrink.getElement(PIZZA, input) << std::endl;

	totalOrders++;

	allOrders[foodAndDrink.getElement(PIZZA, input)] = foodAndDrink.getPrice(PIZZA, input);
}

void doDrink(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders)
{
	int input = -1;
	system("cls");

	std::cout << "Please choose from the selection of drinks.\n";
	foodAndDrink.ShowMenu(DRINK);


	while (input > foodAndDrink.numElements(DRINK) || input < 0)
	{
		std::cin >> input;

		if (input > foodAndDrink.numElements(DRINK) || input < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;


	}
	std::cout << "You have chosen " << foodAndDrink.getElement(DRINK, input) << std::endl;

	allOrders[foodAndDrink.getElement(DRINK, input)] = foodAndDrink.getPrice(DRINK, input);
}

void doTopping(FADClass &foodAndDrink, int &totalOrders, std::map<std::string, double>&allOrders)
{
	int input = -1;
	system("cls");

	std::cout << "Please choose from the selection of toppings.\n";
	foodAndDrink.ShowMenu(TOPPING);


	while (input > foodAndDrink.numElements(TOPPING) || input < 0)
	{
		std::cin >> input;
		if (input > foodAndDrink.numElements(TOPPING) || input < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}

	std::cout << "You have chosen " << foodAndDrink.getElement(TOPPING, input) << std::endl;

	allOrders[foodAndDrink.getElement(TOPPING, input)] = foodAndDrink.getPrice(TOPPING, input);
}

int main()
{

	TableClass chooseTable;
	int table = 0;
	int input = -1;
	char ans = 0;
	char endans = 0;
	int totalOrders = 0;
	double totalCost = 0;

	std::map<std::string, double> allOrders;

	// Allow the user to choose a table
	table = chooseTable.SetupTable();

	FADClass foodAndDrink;

	// Initialize everything. Food, Drink, topping.
	foodAndDrink.Initialize();
	std::cout << foodAndDrink.numElements(PIZZA);

	while (endans != 'n' || totalOrders >= 10)
	{
		doPizza(foodAndDrink, totalOrders, allOrders);

		std::cout << "\nWould you like a drink with that?\n";

		std::cin >> ans;


		if (ans == 'y' || ans == 'Y')
		{
			doDrink(foodAndDrink, totalOrders, allOrders);

			std::cout << "\nWould you like any toppings? (y/n)\n";

			std::cin >> ans;

			if (ans == 'y' || ans == 'Y')
			{
				doTopping(foodAndDrink, totalOrders, allOrders);

				_sleep(3000);

				system("cls");

				std::cout << "Would you like a thin or thick pizza base?\n";
				std::cout << "0 Thin base\n1 Thick base\n";

				while (input < 0 || input > 1)
				{

					std::cin >> input;
					if (input > 1 || input < 0)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					}
					else break;
				}

				if (!input)
				{
					std::cout << "You have chosen a Thin base\n";
				}
				else if (input)
				{
					std::cout << "You have chosen a Thick base\n";
				}

				input = -1;

				system("cls");

				std::cout << "Would you like to place any more orders?\n";

				endans = -1;

				std::cin >> endans;

				if (endans == 'n' || 'N')
					break;
				else continue;
			}
		} 
	}

	std::cout << "You have ordered :\n";

	for (std::map <std::string, double>::iterator i = allOrders.begin(); i != allOrders.end(); ++i)
	{
		std::cout << i->first << std::endl;
		totalCost += i->second;
	}

	std::cout << "Costing a total " << totalCost << " pounds";

	std::cin.get();
	std::cin.get();
	return 0;
}