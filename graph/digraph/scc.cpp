#include "scc.h"
#include "topological.h"

scc::scc(digraph g):scc_count(0)
{
	visited.resize(g.v());
	ids.resize(g.v());
	// Kosaraju's algorithm for strong components	
	topological reverse_tl(g.reverse());
	std::stack<int> order = reverse_tl.topological_order();
	while(!order.empty())
	{
		int s = order.top();
		order.pop();
		if(!visited[s])
		{
			dfs(g, s);
			scc_count++;	
		}
	}
}

void scc::dfs(digraph g, int s)
{
	ids[s] = scc_count;
	visited[s] = true;
	
	const std::vector<int> &adjlist = g.adj(s);
	for(int i =0; i < adjlist.size(); ++i)
	{
		int w = adjlist[i];
		if( !visited[w])
			dfs(g, w);
	}	
}

bool scc::strongly_connected(int v, int w)
{
	return (ids[v] == ids[w]);
}

int scc::count()
{
	return scc_count;
}

int scc::id(int v)
{
	return ids[v];
}

