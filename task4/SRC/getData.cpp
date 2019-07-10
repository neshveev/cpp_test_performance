#include "prog.hpp"

static bool	isValid( const std::string& str )
{
	if (str.length() != 11)
		return false;
	int	digit[8] = {0, 1, 3, 4, 6, 7, 9, 10};

	for (size_t i = 0; i < 8; ++i)
		if (!isdigit(str[digit[i]]))
			return false;

	if (str[2] != ':' || str[8] != ':')
		return false;
	if (str[5] != '-')
		return false;
	return true;
}

static void	getPerson( std::vector<Person>& data, const std::string& str )
{
	int	hh = atoi(str.data());
	int	mm = atoi(str.data() + str.find(':') + 1);
	Time in(hh, mm);

	hh = atoi(str.data() + str.find('-') + 1);
	mm = atoi(str.data() + str.rfind(':') + 1);
	Time out(hh, mm);
	
	Person	p(in, out);
	if (p.getOut() >= p.getIn())
		if (p.getIn() >= Time(8, 0) && p.getOut() <= Time(20, 0)) // suppose that person can not get out after 20:00
			data.push_back(p);
}

void	readData(std::vector<Person>& data, const char* name)
{
	std::ifstream	file(name);
	myAssert(file.is_open(), "File was not open");

	
	while (!file.eof())
	{
		std::string	str;
		getline(file, str);
		if (isValid(str))
			getPerson(data, str);
	}
	myAssert(data.size() > 0, "No data");
	file.close();
}
