#include "FileClass.h"


FileClass::FileClass()
{
}


FileClass::~FileClass()
{
}

bool FileClass::LoadFile(char *fileName, std::map<std::string, double> &returnedValue, int &num)
{
	// Open the file
	std::ifstream loadedFile(fileName, std::ifstream::in);
	std::string string;
	
	// The file failed to open
	if (!loadedFile.is_open())
		return false;

	
	num = 0;

	while (std::getline(loadedFile, string))
	{
		//Skip comments
		if (string[0] == '#')
			continue;
		 
		// Find the position of the assignment operator
		std::size_t sPos = string.find("=");

		// No assignment operators were found, possibly wrong formatting?
		if (sPos == std::string::npos)
			continue;

		// Ignore whitespace
		if(string[sPos-1] == ' ')
			sPos-=1;
		
		std::string tempString;

		
		tempString = string.substr(0, sPos);

		// Load the values and keys into the map container
		if (string[sPos] == '=')
			returnedValue[tempString] = ::atof(string.substr(sPos + 1, (sPos + 1) - string.length()).c_str());
		else
			returnedValue[tempString] = ::atof(string.substr(sPos + 2, (sPos + 2) - string.length()).c_str());

		num++;
	}

	if (returnedValue.empty())
	{
		// There was content in the file but the program failed to load any.
		std::cout << "ERROR: The program failed to load any values from the files. Did you use the right formatting/have you created the files and their items?\n";
		return false;
	}

	// Close the file
	loadedFile.close();
	return true;
}
