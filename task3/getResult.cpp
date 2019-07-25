#include "prog.hpp"

size_t	getIndexMax(double *tab)
{
	size_t	res;
	double	max = tab[0];

	for (size_t i = 0; i < 16; ++i)
		if (max < tab[i])
		{
			max = tab[i];
			res = i;
		}
	return res;
}

static void	getTime(int& mm, int& hh, size_t index)
{
	mm = 30 * (index);
	hh = mm / 60;
	mm -= hh * 60;
	std::cout << std::setw(2) << std::setfill('0') << hh <<
		":" << std::setw(2) << std::setfill('0') << mm;
}

void	printTime(size_t index)
{
	int	mm, hh;

	std::cout << "The largest number of visitors was from ";
	getTime(mm, hh, index);
	std::cout << " to ";
	getTime(mm, hh, ++index);
	std::cout << std::endl;
}
