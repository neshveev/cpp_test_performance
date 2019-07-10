#include "Time.hpp"
#include <iomanip>

Time::Time() {}

Time::Time(int h, int m) : hh(h), mm(m) {}

int const	Time::getHH() const
{ return hh; }

int const	Time::getMM() const
{ return mm; }

std::ostream&	operator<<(std::ostream& out,
				const Time& rhs )
{
	out << std::setw(2) << std::setfill('0') <<
		rhs.getHH() << ":" <<
		std::setw(2) << std::setfill('0') <<
		rhs.getMM();
	return out;
}

bool	Time::operator<=( const Time& rhs ) const
{
	if (hh < rhs.getHH())
		return true;
	if (hh == rhs.getHH())
	{
		if (mm <= rhs.getMM())
			return true;
		else
			return false;
	}
	return false;
	
}

bool	Time::operator>=( const Time& rhs ) const
{
	if (hh > rhs.getHH())
		return true;
	if (hh == rhs.getHH())
	{
		if (mm >= rhs.getMM())
			return true;
		else
			return false;
	}
	return false;
}

void	Time::operator+=( const Time& rhs )
{
	mm += rhs.getMM();
	if (mm > 59)
	{
		++hh;
		mm %= 60;
	}
	hh += rhs.getHH();
	if (hh > 23)
		hh = 24;
}

Time	operator+( const Time& lhs, const Time& rhs )
{
	int	h;
	int	m;

	h = lhs.getHH() + rhs.getHH();
	m = lhs.getMM() + rhs.getMM();

	if (m >= 60)
	{
		m %= 60;
		++h;
	}
	if (h >= 24)
		h = 24;
	return Time(h, m);
}

Time::~Time() {}

