#ifndef _SYMBOL_GRAPH_H
#define _SYMBOL_GRAPH_H

#include "graph.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <istream>

class symbol_graph
{
	public:
		symbol_graph(std::istream &ins, char delimiter);
		graph& g();
		std::string name(int v);
		int index(std::string name);
		~symbol_graph();
	
	private:
		std::vector<std::string> keys;
		std::unordered_map<std::string, int> symbol_table;
		graph *gr;			
};

#endif
