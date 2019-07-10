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
	res = static_cast<int>(rand() * fraction * ((max - min + 1) + min));
	return res;
}

int	getSign()
{
	return (rand() % 3 ? 1 : -1);
}

int main(int argc, char **argv)
{
	myAssert(argc == 2, "Usage: [randNbGen] [nb > 0]");

	int nbStr = atoi(argv[1]);
	myAssert(nbStr > 0, "Param must be int > 0");

	std::string	nameFile = "test";
	nameFile += argv[1];
	std::ofstream	file(nameFile.data());
	myAssert(file.is_open(), "File was not create");

	srand(static_cast<unsigned int>(time(0)));
	rand();
	for (int i = 0; i < nbStr; ++i)
		file << getSign() * getRand(0, 1000) << std::endl;

	file.close();
	return 0;
}
