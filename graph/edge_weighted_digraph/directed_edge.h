#ifndef _DIRECTED_EDGE_H
#define _DIRECTED_EDGE_H

#include <ostream>

class directed_edge;
std::ostream &operator<<(std::ostream &ost, directed_edge &e);

class directed_edge
{
	public:
		directed_edge(int v, int w, double weight);
		double weight();
		int from();
		int to();
		friend std::ostream &operator<<(std::ostream &ost, directed_edge &e);

	private:
		int _from,_to;
		double _weight;
};

#endif
