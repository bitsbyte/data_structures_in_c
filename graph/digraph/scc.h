#ifndef _SCC_H
#define _SCC_H

#include "digraph.h"
#include <vector>

class scc
{
	public:
		scc(digraph g);
		bool  strongly_connected(int v, int w);
		int count();
		int id(int v);
	
	private:
		void dfs(digraph g, int s);
		std::vector<bool> visited;
		std::vector<int> ids;
		int scc_count;	
};

#endif
