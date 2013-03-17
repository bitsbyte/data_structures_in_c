#include "topological.h"
#include "directed_cycle.h"

topological::topological(digraph g):isdag(true)
{
		directed_cycle dc(g);
		//if(!dc.has_cycle())
		//{
			visited.resize(g.v(),0);
			for(int s = 0; s < g.v(); ++s)
			{
				if(!visited[s])
					dfs(g, s);
			}
		//}
		//else
		if(dc.has_cycle())	
			isdag = false;
}

void topological::dfs(digraph g, int s)
{
	visited[s] = true;
	const std::vector<int> &adjlist = g.adj(s);
	for(int i = 0; i < adjlist.size(); ++i)
	{
		int w = adjlist[i];
		if(!visited[w])
			dfs(g, w);	
	}
	reverse_post_order.push(s);
}

bool topological::is_dag()
{
	return isdag;
}

std::stack<int> topological::topological_order()
{
  /* //for graphs with cycle , we need topolical order 
		 // for computing Strongly Connected Components
	if(!isdag)
	{
		while(!reverse_post_order.empty())
			reverse_post_order.pop();
	}	
	*/
	return reverse_post_order;
}
