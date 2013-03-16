#include "cycle.h"
#include <vector>

/*
	assumes no self-loops or parallel edges
*/
cycle::cycle(graph g):hascycle(false)
{
	visited.resize(g.v(), 0);
	for(int s = 0; s < g.v(); ++s)
	{
		if(!visited[s])
			dfs(g, s, s);
	}
}

void cycle::dfs(graph &g, int source, int parent)
{
	visited[source] = true;
	
	const std::vector<int> &adjlist = g.adj(source);
	for(int i = 0 ; i < adjlist.size(); ++i)
	{
		if(!visited[adjlist[i]])	
			dfs(g, adjlist[i], source);
		else if( adjlist[i] != parent)
			hascycle = true;
	}
}

bool cycle::has_cycle()
{
	return hascycle;
}
