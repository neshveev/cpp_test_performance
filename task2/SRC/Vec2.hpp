#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>

class Vec2
{
	double	_x;
	double	_y;

public:
	Vec2();
	Vec2(double, double);
	~Vec2();
	Vec2( const Vec2& rhs );
	Vec2&	operator=( const Vec2& rhs );
	bool	operator==( const Vec2& rhs );

	double	getX() const;
	double	getY() const;

	double	mod();
	void	norm();

	friend Vec2	operator-( const Vec2& lv, const Vec2& rv );

	friend std::ostream& operator<<( std::ostream& out, const Vec2& rhs );
};

#endif
