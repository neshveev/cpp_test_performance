#ifndef PERSON_HPP
#define PERSON_HPP

#include "Time.hpp"

class Person
{
	Time	in;
	Time	out;
	Person();
public:
	Person(Time, Time);

	bool	isInPeriod( const Time& start, const Time& end ) const;

	const Time&	getIn() const;
	const Time&	getOut() const;
	friend std::ostream&	operator<<(std::ostream& out, const Person& rhs );
};

#endif
