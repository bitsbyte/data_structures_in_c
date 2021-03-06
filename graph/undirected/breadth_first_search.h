#ifndef _BREADTH_FIRST_SEARCH_H
#define _BREADTH_FIRST_SEARCH_H
#include "graph.h"
#include <vector>
#include <stack>

class breadth_first_search
{
	public:
		breadth_first_search(graph g, int s);
		bool has_path_to(int v);
		void	path_to(int v, std::stack<int> &path);

	private:
		void bfs(graph g, int s);
		std::vector<bool> visited;
		std::vector<int> parent;
		int source;
};

#endif
