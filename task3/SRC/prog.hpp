#ifndef PROG_HPP
#define PROG_HPP

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

size_t	getIndexMax(double *tab);
void	printTime(size_t index);
void	fillData(double *tab, const char* dir);
void	myAssert(bool condition, const char *error);

#endif
