#ifndef _DIRECTED_CYCLE_H
#define _DIRECTED_CYCLE_H

#include <stack>
#include "digraph.h"

class directed_cycle
{
	public:
		directed_cycle(digraph &g);
		bool has_cycle();
		std::vector<int> cycle();
	
	private:
		void dfs(digraph &g, int  s);
		std::vector<bool> on_stack;
		std::vector<int> vertex_in_cycle;
		std::vector<bool> visited;
		std::vector<int> parent;
		bool hascycle;
};

#endif
