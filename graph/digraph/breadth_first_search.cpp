#include "breadth_first_search.h"
#include <vector>
#include <stack>
#include <queue>

breadth_first_search::breadth_first_search(digraph g, int s):source(s)
{
	visited.resize(g.v(), false);
	parent.resize(g.v(), -1);
	
	bfs(g,s);
}


void breadth_first_search::bfs(digraph g, int s)
{
	std::queue<int> q;
	q.push(s);
	visited[s] = true;	
	
	while(!q.empty())
	{
		int current = q.front();
		q.pop();

    const  std::vector<int> &adjlist = g.adj(current);
  	for(int i = 0 ; i < adjlist.size(); ++i)
  	{
  		if(!visited[adjlist[i]])
  		{
				visited[adjlist[i]] = true;
  			parent[adjlist[i]] = current;
  			q.push(adjlist[i]);		
  		}
  	}	
	}
		
}

void breadth_first_search::path_to(int s, std::stack<int> &path)
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

bool breadth_first_search::has_path_to(int v)
{
	return visited[v];
}
