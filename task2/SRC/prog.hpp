#include <fstream>
#include <string>
#include <cstdlib>
#include "Vec2.hpp"
#include "Quad.hpp"
#include <iostream>

bool	strIsValid( const std::string& str );
void	myAssert(bool condition, const char *error);
Quad	readData(const char* name);
Vec2	getUserPoint();
