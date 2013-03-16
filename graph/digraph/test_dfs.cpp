#include <iostream>
#include "digraph.h"
#include "depth_first_search.h"

using namespace std;

void print_paths(digraph &g, depth_first_search &dfs)
{
  stack<int> p;
  for(int i = 0 ; i < g.v(); ++i)
  {
    cout << "path to " << i << " : " ;
    dfs.path_to(i,p);
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
	depth_first_search dfs1(g1, 0);
	cout << "1st graph: dfs paths : " << endl;
	print_paths(g1, dfs1);

	digraph g2(cin);
	depth_first_search dfs2(g2,0);
	cout << "2nd graph: dfs paths : " << endl;
	print_paths(g2, dfs2);
	return  0;
}
