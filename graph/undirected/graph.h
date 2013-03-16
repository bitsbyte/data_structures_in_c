#ifndef _GRAPH_H
#define _GRAPH_H

#include <istream>
#include <ostream>
#include <vector>

class graph;
std::ostream& operator<<(std::ostream &ost, const graph& g);

class graph
{
	public:
		graph(int V);
		graph(std::istream &ins);
		int v() const;
		int e() const;
		void add_edge(int v, int w);
		const std::vector<int>& adj(int v) const;
		
		friend	std::ostream& operator<<(std::ostream &ost, const graph& g);
	private:
	
		int V, E;
		std::vector< std::vector<int> > adjlist;			
};


#endif
