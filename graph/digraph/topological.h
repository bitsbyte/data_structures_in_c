#ifndef _TOPOLOGICAL_H
#define _TOPOLOGICAL_H

#include "digraph.h"
#include <vector>
#include <stack>

class topological
{
	public:
		topological(digraph g);
		bool  is_dag();
		std::stack<int> topological_order();
		
	private:
		void dfs(digraph g, int s);
		std::vector<bool> visited;
		std::stack<int> reverse_post_order;
		bool isdag;		
};
	
#endif
