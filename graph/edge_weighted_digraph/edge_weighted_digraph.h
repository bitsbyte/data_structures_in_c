#ifndef _EDGE_WEIGHTED_DIGRAPH_H
#define _EDGE_WEIGHTED_DIGRAPH_H

#include <vector>
#include <ostream>
#include <istream>
#include "directed_edge.h"

class edge_weighted_digraph;
std::ostream &operator<<(std::ostream &ost, edge_weighted_digraph &g);

class edge_weighted_digraph
{
	public:
		edge_weighted_digraph(int V);
		edge_weighted_digraph(std::istream &ins);
		int v();
		int e();
		void add_edge(directed_edge eg);
		std::vector<directed_edge> adj(int v);
		std::vector<directed_edge> edges();
		friend std::ostream &operator<<(std::ostream &ost, edge_weighted_digraph &g);
	
	private:
		int V,E;
		std::vector< std::vector<directed_edge> > adjlist;
};

#endif
