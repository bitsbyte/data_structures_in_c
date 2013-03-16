#include "digraph.h"

digraph::digraph(int v)
{
	E = 0;
	V = v;
	adjlist.resize(v);
}

digraph::digraph(std::istream &ins)
{
	int i,v,w,edge;

	E = 0;
	ins >> V;	
	ins >> edge;
	adjlist.resize(V);
	
	for(i = 0 ; i < edge; ++i)
	{
		ins >> v >> w;
		add_edge(v, w);
	}	
}

int digraph::v() const
{
	return V;
}

int digraph::e() const
{
	return E;
}

void digraph::add_edge(int v, int  w)
{
	adjlist[v].push_back(w);
	E++;
}

const std::vector<int>& digraph::adj(int v) const
{
	return adjlist[v];
}

digraph digraph::reverse()
{	
	digraph rgraph(V);
	for(int from = 0; from < V; ++from)	
		for(int i = 0 ; i < adjlist[from].size(); ++i)
		{
			int to = adjlist[from][i];
			rgraph.add_edge(to,from); // reversed to and from
		}

	return rgraph;
}

std::ostream& operator<<(std::ostream& ost, const digraph& g)
{
	ost << g.v() << " vertices, " << g.e() << " edges\n";
	for(int v = 0; v < g.v(); v++)
	{
		ost << v << ":\t";
		for(int i = 0 ; i < g.adj(v).size(); ++i)
			ost << g.adj(v)[i] << " ";
		ost << "\n";
	}

	return ost;
}

