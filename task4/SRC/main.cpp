#include "prog.hpp"

void	myAssert(bool condition, const char *error)
{
	if (!condition)
	{
		std::cout << error << std::endl;
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	myAssert(argc == 2, "Usage: [prog] [file]");
	std::vector<Person>	data;
	readData(data, argv[1]);

	std::vector<int>	res;

	Time	period = getPeriod();

	fillResData(data, res, period);

	printResTime(res, period);

	return 0;
}
