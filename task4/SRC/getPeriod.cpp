#include "prog.hpp"

Time	getPeriod()
{
	int	hh;
	int	mm;

	std::cout << "Please enter the length of the time"
		" interval for calculate the result (in minutes)" <<
		std::endl;
	while (1)
	{
		std::cout << "Minutes : ";
		std::cin >> mm;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32000, '\n');
			std::cout << "Uops! Try again!" << std::endl;
		}
		else if (mm <= 0 || mm > 720)
			std::cout << "Uops! [0 < mm <= 720] Try again!" << std::endl;
		else
			break ;
	}
	hh = mm / 60;
	mm %= 60;
	std::cout << "==========================================\n" << std::endl;

	return Time(hh, mm);
}
