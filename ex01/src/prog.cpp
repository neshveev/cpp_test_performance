#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

enum	Data
{
	PERCENTILE,
	MEDIAN,
	AVERAGE,
	MAX,
	MIN,
	SIZE
};

void	myAssert(bool condition, const char *error)
{
	if (!condition)
	{
		std::cout << error << std::endl;
		exit(1);
	}
}

template <class T>
void	mySortTab(std::vector<T>& tab)
{
	for (size_t big = 0; big < tab.size() - 1; ++big)
		for (size_t lit = big + 1; lit < tab.size(); ++lit)
			if (tab[big] > tab[lit])
			{
				T	tmp;
				tmp = tab[big];
				tab[big] = tab[lit];
				tab[lit] = tmp;
			}
}

bool	strIsValid(const std::string& str)
{
	size_t	sign;

	if (str.length() == 0)
		return false;
	sign = (str[0] == '-' || str[0] == '+' ? 1 : 0);
	for (size_t i = sign; i < str.length(); ++i)
		if (!isdigit(str[i]))
			return false;
	return true;
}

void	getRes(const std::vector<int>& tab, int res[])
{
	res[MIN] = tab[0];
	res[MAX] = tab[tab.size() - 1];
	res[MEDIAN] = tab.size() % 2 ? tab[tab.size() / 2] : tab[tab.size() / 2 - 1];
	
	int	sum = 0;
	for (size_t i = 0; i < tab.size(); ++i)
		sum += tab[i];
	res[AVERAGE] = sum / tab.size();

	double	percent = 100.0 / static_cast<double>(tab.size());
	int	index = static_cast<int>(90 / percent);
	if (!(90 - index * percent))
		--index;
	res[PERCENTILE] = tab[index];
}

void	readInTab(std::vector<int>& tab, const char* name)
{
	std::ifstream	file(name);
	myAssert(file.is_open(), "File was not open");

	while (!file.eof())
	{
		std::string	str;
		getline(file, str);
		if (strIsValid(str))
			tab.push_back(atoi(str.data()));
	}
	myAssert(tab.size() > 0, "No data");
}

int	main(int argc, char **argv)
{
	myAssert(argc == 2, "Usage: [prog] [file]");

	std::vector<int>	tab;

	readInTab(tab, argv[1]);
	mySortTab(tab);

	int	res[SIZE];
	getRes(tab, res);
	std::cout <<	"90percentile<" << res[PERCENTILE]	<<
			">\nmedian<"	<< res[MEDIAN]		<<
			">\naverage<"	<< res[AVERAGE]		<<
			">\nmax<"	<< res[MAX]		<<
			">\nmin<"	<< res[MIN]		<<
		">" << std::endl;
	return 0;
}

//void	printTab(const std::vector<int>& tab)
//{
//	for (size_t i = 0; i < tab.size(); ++i)
//		std::cout << tab[i] << ";";
//	std::cout << std::endl;
//}
