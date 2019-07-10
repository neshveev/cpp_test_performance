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
	myAssert(argc == 2, "Usage: [prog] [dir]");

	double	tab[16] = {0};
	
	fillData(tab, argv[1]);
	printTime(getIndexMax(tab));
	return 0;
}
