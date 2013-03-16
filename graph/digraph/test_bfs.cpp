#include <iostream>
#include "digraph.h"
#include "breadth_first_search.h"

using namespace std;

void print_paths(digraph &g, breadth_first_search &bfs)
{
  stack<int> p;
  for(int i = 0 ; i < g.v(); ++i)
  {
    cout << "path to " << i << " : " ;
    bfs.path_to(i,p);
    while(!p.empty())
    {
      cout <<  p.top() << " " ;
      p.pop();
    }
    cout << endl;
  }

}


int main(int argc, char* argv[])
{
	digraph g1(6);
	breadth_first_search bfs1(g1, 0);
	cout << "1st graph: bfs paths : " << endl;
	print_paths(g1, bfs1);

	digraph g2(cin);
	breadth_first_search bfs2(g2,8);
	cout << "2nd graph: bfs paths : " << endl;
	print_paths(g2, bfs2);
	return  0;
}
