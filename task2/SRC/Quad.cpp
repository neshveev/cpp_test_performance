#include "Quad.hpp"
#include <cmath>

Quad::Quad() {}

Quad::~Quad() {}

Quad::Quad(Vec2 a, Vec2 b, Vec2 c, Vec2 d) :
		_a(a), _b(b), _c(c), _d(d) {}

const Vec2&	Quad::getA() const
{
	return _a;
}

const Vec2&	Quad::getB() const
{
	return _b;
}

const Vec2&	Quad::getC() const
{
	return _c;
}

const Vec2&	Quad::getD() const
{
	return _d;
}

bool	Quad::isVertex( const Vec2& point )
{
	if (_a == point || _b == point || _c == point || _d == point)
	{
		std::cout << "Point - vertex of the quadrilateral." << std::endl;
		return true;
	}
	return false;
}

bool	sideQuad( Vec2& a, Vec2& b, const Vec2& p)
{
	Vec2	pa = a - p;
	Vec2	pb = b - p;

	pa.norm();
	pb.norm();

	if (fabs(pa.getX() * -1 - pb.getX()) < 1e-5 &&
		fabs(pa.getY() * -1 - pb.getY()) < 1e-5)
		return true;
	return false;
}
bool	Quad::isSide( const Vec2& point )
{
	if (!sideQuad(_a, _b, point) &&
		!sideQuad(_b, _c, point) &&
		!sideQuad(_c, _d, point) &&
		!sideQuad(_d, _a, point))
		return false;
	
	std::cout << "The point lies on the sides of the quadrilateral." << std::endl;

	return true;
}

double	sideVector( Vec2& a, Vec2& b, const Vec2& p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY()) -
		(b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool	Quad::isInto( const Vec2& point )
{
	if (sideVector(_a, _b, point) > 0 ||
		 sideVector(_b, _c, point) > 0 ||
		 sideVector(_c, _d, point) > 0 ||
		 sideVector(_d, _a, point) > 0)
	{
		std::cout << "The dot outside the quadrilateral." << std::endl;
		return false;
	}
	std::cout << "The dot inside the quadrilateral." << std::endl;
	return true;			
}

std::ostream&	operator<<(
		std::ostream& out, const Quad& rhs )
{
	out << rhs.getA() << std::endl; 
	out << rhs.getB() << std::endl; 
	out << rhs.getC() << std::endl; 
	out << rhs.getD() << std::endl; 
	return out;
}
