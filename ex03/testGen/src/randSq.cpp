#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

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
	srand(static_cast<unsigned int>(time(0)));
	rand();

	char	c = '0';
	for (size_t n = 0; n < 5; ++n)
	{
		std::string	name = "kassa#";
		++c;
		name += c;
		std::ofstream	file(name.data());
		myAssert(file.is_open(), "File was not create");

		for (size_t i = 0; i < 16; ++i)
			file << getRand(0, 10) << "." << getRand(0, 99) << std::endl;
		file.close();
	}
	return 0;
}
