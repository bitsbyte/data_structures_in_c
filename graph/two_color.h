#ifndef _TWO_COLOR_H
#define _TWO_COLOR_H

#include <vector>
#include "graph.h"

class two_color
{
	public:
		two_color(graph g);
		bool is_bipartite();
	
	private:
		enum COLOR { NONE, WHITE, BLACK };
		void dfs(graph g, int s, COLOR parent);
		std::vector<bool> visited;
		std::vector<COLOR> color;
		bool is_two_colorable;
};

#endif
