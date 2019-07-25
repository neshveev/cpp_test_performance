#include "Vec2.hpp"
#include <cmath>

Vec2::Vec2() : _x(0), _y(0) {}

Vec2::Vec2(double x, double y) : _x(x), _y(y) {}

Vec2::~Vec2() {}


double	Vec2::getX() const
{
	return _x;
}

double	Vec2::getY() const
{
	return _y;
}

Vec2::Vec2( const Vec2& rhs )
{
	*this = rhs;
}

Vec2&	Vec2::operator=( const Vec2& rhs )
{
	if (this == &rhs)
		return *this;
	_x = rhs.getX();
	_y = rhs.getY();
	return *this;
}

bool	Vec2::operator==( const Vec2& rhs )
{
	if (fabs(fabs(_x) - fabs(rhs.getX())) > 10e-8)
		return false;
	if (fabs(fabs(_y) - fabs(rhs.getY())) > 10e-8)
		return false;
	return true;
}

Vec2	operator-( const Vec2& lv, const Vec2& rv )
{
	double	x = lv.getX() - rv.getX();
	double	y = lv.getY() - rv.getY();

	Vec2	res = Vec2(x, y);
	return res;
}

double	Vec2::mod()
{
	return sqrt(_x * _x + _y * _y);
}
void	Vec2::norm()
{
	double	len;

	len = Vec2::mod();
	_x /= len;
	_y /= len;
}

std::ostream& operator<<(
		std::ostream& out, const Vec2& rhs )
{
	out << "<" << rhs.getX() << "><" << rhs.getY() << ">";
	return out;
}

