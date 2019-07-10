#include <fstream>
#include <string>
#include <cstdlib>
#include "Vec2.hpp"
#include "Quad.hpp"
#include <iostream>

#include "prog.hpp"

Quad	readData(const char* name)
{
	std::ifstream	file(name);
	myAssert(file.is_open(), "File was not open");

	Vec2	point[4];

	for (size_t i = 0; i < 4; ++i)
	{
		std::string	str;
		getline(file, str);
		myAssert(strIsValid(str), "Data is not valid");
		point[i] = Vec2(atof(str.data() + 1),
			atof(str.data() + str.rfind('<') + 1));
	}
	file.close();
	return Quad(point[0], point[1], point[2], point[3]);
}

static double	getXY(bool x)
{
	double	res;
	while (1)
	{
		std::cout << (x ? "X = " : "Y = ");
		std::cin >> res;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32000, '\n');
			std::cout << "Ops! Try again!" << std::endl;
		}
		else
			break ;
	}
	return res;
}

Vec2	getUserPoint()
{
	std::cout << "Enter point coordinates." << std::endl;

	double	x = getXY(1);
	double	y = getXY(0);
	return Vec2(x, y);
}
