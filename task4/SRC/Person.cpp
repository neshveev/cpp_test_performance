#include "Person.hpp"

Person::Person() {}

Person::Person( Time i, Time o) : in(i), out(o) {}

bool	Person::isInPeriod( const Time& start, const Time& end ) const
{
	if (in <= start)
	{
		if (out >= start)
			return true;
		else
			return false;
	}
	else
	{
		if (in <= end)
			return true;
		else
			return false;
	}
}

const Time&	Person::getIn() const
{ return in; }

const Time&	Person::getOut() const
{ return out; }

std::ostream&	operator<<(std::ostream& out,
				const Person& rhs )
{
	out << rhs.getIn() << "-" << rhs.getOut();
	return out;
}
