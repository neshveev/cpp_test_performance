#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

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

	int	x1 = getRand(0, 10) * getSign();
	int	y1 = getRand(0, 10) * getSign();

	int	x2 = x1 + getRand(1, 5);
	int	y2 = y1 + getRand(1, 5);

	int	x3 = x2 + getRand(1, 5);
	int	y3 = y1;

	int	x4 = x1;
	int	y4 = y1 - getRand(1, 5);


	file << "<" << x1 << "." << getRand(0, 99) << ">" << "<" << y1 << "." << getRand(0, 99) << ">" << std::endl;
	file << "<" << x2 << "." << getRand(0, 99) << ">" << "<" << y2 << "." << getRand(0, 99) << ">" << std::endl;
	file << "<" << x3 << "." << getRand(0, 99) << ">" << "<" << y3 << "." << getRand(0, 99) << ">" << std::endl;
	file << "<" << x4 << "." << getRand(0, 99) << ">" << "<" << y4 << "." << getRand(0, 99) << ">" << std::endl;


	file.close();
	return 0;
}
