#include "edge_weighted_digraph.h"

edge_weighted_digraph::edge_weighted_digraph(int v):
	V(v),E(0)
{
	adjlist.resize(V);
}

edge_weighted_digraph::edge_weighted_digraph(std::istream &ins):
	E(0)
{
	int egs,v,w;
	float wt;
	
	ins >> V >> egs;
	adjlist.resize(V);	

	for(int i = 0; i < egs; ++i)
	{
		ins >> v >> w >> wt;
		add_edge(directed_edge(v,w,wt));
	}
}

int edge_weighted_digraph::e()
{
	return E;
}

int edge_weighted_digraph::v()
{
	return V;
}

void edge_weighted_digraph::add_edge(directed_edge eg)
{
	adjlist[eg.from()].push_back(eg);
	E++;
}

std::vector<directed_edge> edge_weighted_digraph::adj(int v)
{
	return adjlist[v];
}

std::vector<directed_edge> edge_weighted_digraph::edges()
{
	std::vector<directed_edge> all_edges;
	for(int s = 0; s < V; ++s)
	{
		const std::vector<directed_edge> &adjc = adj(s);
		all_edges.insert(all_edges.end(), adjc.begin(), adjc.end());	
	}
	return all_edges;	
}

std::ostream &operator<<(std::ostream &ost, edge_weighted_digraph &g)
{
	ost << g.V << " vertices, " << g.E << " edges\n";
	if( g.E == 0) return ost;

	for(int s = 0; s < g.V; ++s)
	{
		std::vector<directed_edge> adjc = g.adj(s);
		for(int i = 0; i < adjc.size(); ++i)
		{
			ost << adjc[i] << "\t";
		}
		ost << "\n";
	}

	return ost;
}


