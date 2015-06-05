#include "FADClass.h"
#include "FileClass.h"


FADClass::FADClass()
{
}

FADClass::~FADClass()
{
	// If these classes have been used (and therefor memory allocated) deallocate the memory
	if (cDrink)
	{
		delete cDrink;
		cDrink = NULL;
	}

	if (cPizza)
	{
		delete cPizza;
		cPizza = NULL;
	}

	if (cTopping)
	{
		delete cTopping;
		cTopping = NULL;
	}
}


bool FADClass::Initialize()
{
	// Initialize all the classes we'll be using
	cDrink = new DrinkClass();

	if (!cDrink)
		return false;

	if (!cDrink->Initialize())
		return false;

	cPizza = new PizzaClass();

	if (!cPizza)
		return false;

	if (!cPizza->Initialize())
		return false;

	cTopping = new ToppingClass();

	if (!cTopping)
		return false;

	if (!cTopping->Initialize())
		return false;

	return true;
}

void FADClass::ShowMenu(Itype type)
{
	// Show the menu based on type given
	switch (type)
	{
		case DRINK:
			return cDrink->printAll();
		case PIZZA:
			return cPizza->printAll();
		case TOPPING:
			return cTopping->printAll();
		default: return;
	}
}

double FADClass::getPrice(Itype type, int ID)
{
	// Return price based on type given and respected ID
	switch (type)
	{
		case DRINK:
			return cDrink->getPrice(ID);
		case PIZZA:
			return cPizza->getPrice(ID);
		case TOPPING:
			return cTopping->getPrice(ID);
		default: return -1;
	}
}

int FADClass::numElements(Itype type)
{
	// Return the total number of elements based on the given type
	switch (type)
	{
		case DRINK:
			return cDrink->numDrinks();
		case PIZZA:
			return cPizza->numPizzas();
		case TOPPING:
			return cTopping->numToppings();
		default: return -1;
	}
}

std::string FADClass::getElement(Itype type, int ID)
{
	// Get the name of the element based on its type and ID
	switch (type)
	{
		case DRINK:
			return cDrink->getDrinkInfo(ID);
		case PIZZA:
			return cPizza->getPizzaInfo(ID);
		case TOPPING:
			return cTopping->getToppingInfo(ID);
	}
	return "error";
}
