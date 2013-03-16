#ifndef _STRING_UTIL_H
#define _STRING_UTIL_H

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> &split(std::string &s, 
																char delim, 
																std::vector<std::string> &elements)
{
	std::stringstream sstr(s);
	std::string element;
	while(std::getline(sstr, element, delim))
	{
		elements.push_back(element);
	}
	return elements;
}

#endif

