#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void	myAssert(bool condition, const char *error)
{
	if (!condition)
	{
		std::cout << error << std::endl;
		exit(1);
	}
}

int getRand(int min, int max)
{
	double	fraction;
	int	res;

	fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1);
	res = static_cast<int>(rand() * fraction * ((max - min + 1)) + min);
	return res;
}

int	getSign()
{
	return (rand() % 3 ? 1 : -1);
}

int main(int argc, char **argv)
{
	myAssert(argc == 2, "Usage: [randNbGen] [test name]");

	std::ofstream	file(argv[1]);
	myAssert(file.is_open(), "File was not create");

	srand(static_cast<unsigned int>(time(0)));
	rand();

	int	len = getRand(20, 500);
	for (int i = 0; i < len; ++i)
	{
		int	hh = getRand(8, 19);
		int	mm = getRand(8, 19);

		file << std::setw(2) << std::setfill('0') << hh;
		file << ":";
		file << std::setw(2) << std::setfill('0') << mm;
		file << "-";

		hh = hh + getRand(0, 2);
		mm = mm + getRand(0, 59);

		if (mm > 59)
		{
			++hh;
			mm %= 59;
		}

		if (hh > 19)
			hh = 19;


		file << std::setw(2) << std::setfill('0') << hh;
		file << ":";
		file << std::setw(2) << std::setfill('0') << mm << std::endl;
	}
	file.close();
	return 0;
}
