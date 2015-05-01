#include "FileClass.h"


FileClass::FileClass()
{
}


FileClass::~FileClass()
{
}

bool FileClass::LoadFile(char *fileName, std::map<std::string, double> &returnedValue, int &num)
{
	std::ifstream loadedFile(fileName);
	std::string string;
	
	if (!loadedFile.is_open())
		return false;

	
	num = 0;

	while (std::getline(loadedFile, string))
	{
		//Skip comments
		if (string[0] == '#')
			continue;
		 
		std::size_t sPos = string.find("=");

		if (sPos == std::string::npos)
			continue;

		if(string[sPos-1] == ' ')
			sPos-=1;
		
		std::string tempString;

		
		tempString = string.substr(0, sPos);

		
		if (string[sPos] == '=')
			returnedValue[tempString] = ::atof(string.substr(sPos + 1, (sPos + 1) - string.length()).c_str());
		else
			returnedValue[tempString] = ::atof(string.substr(sPos + 2, (sPos + 2) - string.length()).c_str());

		num++;
	}

	loadedFile.close();
	return true;
}
