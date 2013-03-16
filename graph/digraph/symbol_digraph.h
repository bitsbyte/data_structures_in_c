#ifndef _SYMBOL_GRAPH_H
#define _SYMBOL_GRAPH_H

#include "digraph.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <istream>

class symbol_digraph
{
	public:
		symbol_digraph(std::istream &ins, char delimiter);
		digraph& g();
		std::string name(int v);
		int index(std::string name);
		~symbol_digraph();
	
	private:
		std::vector<std::string> keys;
		std::unordered_map<std::string, int> symbol_table;
		digraph *gr;			
};

#endif
