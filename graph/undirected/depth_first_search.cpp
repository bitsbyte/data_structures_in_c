#include "depth_first_search.h"
#include <vector>
#include <stack>

depth_first_search::depth_first_search(graph g, int s):source(s)
{
	visited.resize(g.v(), false);
	parent.resize(g.v(), -1);
	
	dfs(g,s);
}


void depth_first_search::dfs(graph g, int s)
{
	visited[s] = true;
	
  const  std::vector<int> &adjlist = g.adj(s);
	for(int i = 0 ; i < adjlist.size(); ++i)
	{
		if(!visited[adjlist[i]])
		{
			parent[adjlist[i]] = s;
			dfs(g, adjlist[i]);
		}
	}	
}

void depth_first_search::path_to(int s, std::stack<int> &path)
{
	if(!has_path_to(s)) return;
	
	path.push(s);			
	while(s != source && s >= 0)
	{
		s = parent[s];
		if(s >= 0)
			path.push(s);
	}
}

bool depth_first_search::has_path_to(int v)
{
	return visited[v];
}
