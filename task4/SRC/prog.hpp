#ifndef PROG_HPP
#define PROG_HPP

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Time.hpp"
#include "Person.hpp"
#include <cstdlib>

void	myAssert(bool condition, const char *error);
void	readData(std::vector<Person>& data, const char* name);
Time	getPeriod();
void	fillResData( const std::vector<Person>& data,
		std::vector<int>& res, const Time& period );
void	printResTime( const std::vector<int>& res, const Time& period);

#endif
