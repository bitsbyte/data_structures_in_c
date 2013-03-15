#include "graph.h"

graph::graph(int v)
{
	E = 0;
	V = v;
	adjlist.resize(v);
}

graph::graph(std::istream &ins)
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

int graph::v() const
{
	return V;
}

int graph::e() const
{
	return E;
}

void graph::add_edge(int v, int  w)
{
	adjlist[v].push_back(w);
	adjlist[w].push_back(v);
	E++;
}

const std::vector<int>& graph::adj(int v) const
{
	return adjlist[v];
}


std::ostream& operator<<(std::ostream& ost, const graph& g)
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

