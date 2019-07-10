#include "prog.hpp"

void	printResTime( const std::vector<int>& res, const Time& period)
{
	int max = 0;

	for (size_t i = 0; i < res.size(); ++i)
		if (res[i] > max)
			max = res[i];
	std::cout << "Time interval : " << period << std::endl;
	std::cout << "Peak attendance was:" << std::endl;
	for (size_t index = 0; index < res.size(); ++index)
		if (res[index] == max)
		{
			Time	start(8, 0);
			Time	end = start + period;

			for (size_t i = 0; i < index; ++i)
			{
				start += period;
				end += period;
				if (end >= Time(20, 1))
					end = Time(20, 0);
			}
			std::cout << Person(start, end) << std::endl;
		}
	std::cout << "Number of visitors per peak : " << max << std::endl;
}
