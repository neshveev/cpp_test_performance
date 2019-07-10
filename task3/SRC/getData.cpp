#include "prog.hpp"

static bool	strIsValid(const std::string& str)
{
	myAssert(str.length() != 0, "Error str in file");
	
	int	dot = 0;	
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
			++dot;
		myAssert(str[i] == '.' || isdigit(str[i]),
			"Error str in file");
	}
	myAssert(dot < 2, "Error str int file");
	return true;
}

static void	readInTab(double *tab, std::string name)
{
	std::ifstream	file(name.data());
	myAssert(file.is_open(), "File was not open");

	for (size_t i = 0; i < 16; ++i)
	{
		std::string	str;
		getline(file, str);
		if (strIsValid(str))
			tab[i] += atof(str.data());
	}
	file.close();
}

void	fillData(double *tab, const char* dir)
{
	std::string	path;
	path = "./";
	path += dir;
	path += "/kassa#";
	char	c = '0';

	// "crutches" because I have not found a nice method
	// of reading files from a folder for any OS
	for (size_t i = 0; i < 5; ++i)
	{
		++c;
		readInTab(tab, path + c);
		
	}
}
