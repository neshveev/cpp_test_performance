#include <string>
#include <iostream>
#include <cstdlib>

void	myAssert(bool condition, const char *error)
{
	if (!condition)
	{
		std::cout << error << std::endl;
		exit(1);
	}
}

bool	strIsValid( const std::string& str )
{
	myAssert(str.length() != 0, "Error format: Empty line");
	
	size_t	match[4];
	match[0] = str.find('<');
	match[1] = str.find('>');
	match[2] = str.find('<', 1);
	match[3] = str.find('>', match[1] + 1);

	myAssert(match[0] == 0 && match[3] == str.length() - 1,
			"Error format: extra char befor or after '<x><y>'");

	myAssert(match[0] != match[2] && match[1] != match[3],
				"Error format: lacking '</>'");
	for (size_t i = 0; i < 4; ++i)
		myAssert(match[i] != -1, "Error format: lacking '</>'");
	myAssert(match[2] - match[1] == 1,
			"Error format: extra symbols between ><");
	myAssert(match[1] - match[0] > 1,
			"Error format: lack X");
	myAssert(match[3] - match[2] > 1,
			"Error format: lack Y");

	int	dot = 0;
	for (size_t i = (str[match[0] + 1] == '-' ? match[0] + 2 : match[0] + 1); i < match[1]; ++i)
	{
		myAssert(isdigit(str[i]) || str[i] == '.',
				"Error format: wrong X");
		if (str[i] == '.')
			++dot;
		myAssert(dot < 2, "Error format: extra dot in X");
	}
	dot = 0;
	for (size_t i = (str[match[2] + 1] == '-' ? match[2] + 2 : match[2] + 1); i < match[3]; ++i)
	{
		if (str[match[2]] + 1 == '-')
			++i;
		myAssert(isdigit(str[i]) || str[i] == '.',
				"Error format: wrong Y");
		if (str[i] == '.')
			++dot;
		myAssert(dot < 2, "Error format: extra dot in Y");
	}
	return true;
}
