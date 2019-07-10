#ifndef QUAD_HPP
#define QUAD_HPP

#include "Vec2.hpp"
#include <iostream>

class Quad
{
	Vec2	_a;
	Vec2	_b;
	Vec2	_c;
	Vec2	_d;

	Quad();
public:
	Quad(Vec2, Vec2, Vec2, Vec2);
	~Quad();

	const Vec2&	getA() const;
	const Vec2&	getB() const;
	const Vec2&	getC() const;
	const Vec2&	getD() const;

	bool	isVertex( const Vec2& point );
	bool	isSide( const Vec2& point );
	bool	isInto( const Vec2& point );
	friend std::ostream&	operator<<( std::ostream& out, const Quad& rhs );
};

#endif
