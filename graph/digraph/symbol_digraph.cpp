#include "symbol_digraph.h"
#include "string/string_util.h"
#include <istream>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

symbol_digraph::symbol_digraph(std::istream &ins, char delimiter)
{
	std::string line;
	std::string input = "";
	std::vector<std::string> elements;
	// 1st pass on input stream	
	int count = 0;
	while( std::getline(ins, line))
	{
		input += line + "\n";
		elements.clear();
		split(line, delimiter, elements);
		for(int i = 0; i < elements.size(); ++i)	
		{
			if(symbol_table.find(elements[i]) == symbol_table.end()) 
				symbol_table[elements[i]] = count++;
		}
	}

	keys.resize(symbol_table.size());
	for(auto it = symbol_table.begin() ; it != symbol_table.end(); ++it)
	{
		keys[it->second] = it->first;
	}
	
	gr = new digraph(keys.size());
	//reset input stream for 2nd pass	
	std::istringstream inputstream(input);
	while( std::getline(inputstream,line))
	{
		elements.clear();
		split(line, delimiter, elements);
		int parent = symbol_table[elements[0]];
		for(int i = 1; i < elements.size(); ++i)
		{
			gr->add_edge(parent, symbol_table[elements[i]]);
		}
	}
		
}

symbol_digraph::~symbol_digraph()
{
	delete gr;
}

digraph& symbol_digraph::g()
{
	return *gr;
}

std::string symbol_digraph::name(int v)
{
	return keys[v];
}

int symbol_digraph::index(std::string name)
{
	return symbol_table[name];
}

