#ifndef _DIGRAPH_H
#define _DIGRAPH_H

#include <istream>
#include <ostream>
#include <vector>

class digraph;
std::ostream& operator<<(std::ostream &ost, const digraph& g);

class digraph
{
	public:
		digraph(int V);
		digraph(std::istream &ins);
		int v() const;
		int e() const;
		void add_edge(int v, int w);
		const std::vector<int>& adj(int v) const;
		digraph reverse();
		
		friend	std::ostream& operator<<(std::ostream &ost, const digraph& g);
	
	private:
		int V, E;
		std::vector< std::vector<int> > adjlist;			
};


#endif
