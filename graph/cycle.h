#ifndef _CYCLE_H
#define _CYCLE_H

#include "graph.h"

class cycle
{
	public:
		cycle(graph g);
		bool has_cycle();
	
	private:
		void dfs(graph &g, int source, int parent);	
	
		bool hascycle;
		std::vector<int> visited;
			
};

#endif
