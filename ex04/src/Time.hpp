#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

class Time
{
	int hh;
	int mm;
public:
	Time();
	Time(int, int);

	int const	getHH() const;
	int const	getMM() const;

	friend std::ostream&	operator<<(std::ostream& out, const Time& rhs );
	bool	operator<=( const Time& rhs ) const;
	bool	operator>=( const Time& rhs ) const;
	void	operator+=( const Time& rhs );
	friend Time	operator+(
		const Time& lhs, const Time& rhs );

	~Time();
};

#endif
