#include "prog.hpp"

static int	countPersonInPeriod( const std::vector<Person>& data,
		const Time& start, const Time& end )
{
	int	res = 0;

	for (size_t i = 0; i < data.size(); ++i)
		if (data[i].isInPeriod(start, end))
			++res;
	return res;
}

void	fillResData( const std::vector<Person>& data,
		std::vector<int>& res, const Time& period )
{
	Time	start(8, 0);
	Time	end(20, 0);
	
	while (!(end <= start))
	{
		res.push_back(countPersonInPeriod(
				data, start, start + period));
		start += period;
	}
}
