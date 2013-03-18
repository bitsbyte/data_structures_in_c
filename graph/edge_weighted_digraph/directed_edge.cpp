#include "directed_edge.h"

directed_edge::directed_edge(int v, int w, double weight):
	_from(v), _to(w), _weight(weight)
{
}

double directed_edge::weight()
{
	return _weight;
}

int directed_edge::to()
{
	return _to;
}

int directed_edge::from()
{
	return _from;
}

std::ostream &operator<<(std::ostream &ost, directed_edge &e)
{
	ost << e._from << " --" << e._weight << "--> " << e._to ;
	return ost;
}
