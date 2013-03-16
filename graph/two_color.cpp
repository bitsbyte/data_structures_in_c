#include "two_color.h"
#include <vector>

two_color::two_color(graph g):is_two_colorable(true)
{
	color.resize(g.v(), NONE);
	visited.resize(g.v(), 0);
	
	for(int s = 0; s < g.v(); ++s)
	{
		if(!visited[s])		
			dfs(g, s, WHITE);
	}	
			
}

void two_color::dfs(graph g, int s, COLOR parent)
{
	visited[s] = true;
	color[s] = (parent == WHITE ? BLACK : WHITE);
	
	const	std::vector<int> &adjlist = g.adj(s);
	for(int i = 0; i < adjlist.size(); ++i)
	{
		int d = adjlist[i];
		if( !visited[d] )
		{
			dfs(g, d, color[s]);	
		}
		else if( color[s] == color[d] )
			is_two_colorable = false;
	}
}

bool two_color::is_bipartite()
{
	return is_two_colorable;
}
