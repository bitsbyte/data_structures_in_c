#include "directed_cycle.h"

directed_cycle::directed_cycle(digraph &g):hascycle(false)
{
	on_stack.resize(g.v(), false);
	visited.resize(g.v(), false);
	parent.resize(g.v(), -1);

	for(int s=0; s < g.v(); ++s)
	{
		if(!visited[s])
			dfs(g, s);
	}	
}

void directed_cycle::dfs(digraph &g, int s)
{
	visited[s] = true;
	on_stack[s] = true;

	const std::vector<int> &adjlist	= g.adj(s);
	for(int i = 0; i < adjlist.size(); ++i)
	{
		int w = adjlist[i];
		if( !visited[w])
		{
			parent[w] = s;
			dfs(g, w);	
		}
		else if( on_stack[w] )
		{
			// cycle is present store it
			hascycle = true;
			// insert dummy to get different cycles	
			vertex_in_cycle.push_back(-1);
			int v = s;
			while( v != w)
			{
				vertex_in_cycle.push_back(v);
				v = parent[v];
			}
			vertex_in_cycle.push_back(w);			
		}
	}	

	on_stack[s] = false;
}

bool directed_cycle::has_cycle()
{
	return hascycle;
}

std::vector<int> directed_cycle::cycle()
{
	return vertex_in_cycle;
}
