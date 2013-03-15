#include <iostream>
#include "graph.h"
#include "depth_first_search.h"
#include "breadth_first_search.h"


using namespace std;

void print_paths(graph &g, depth_first_search &dfs)
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

void print_paths(graph &g, breadth_first_search &bfs)
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
	graph g1(6);
	
	cout << "first graph: " << endl;
	cout << g1 << endl;
	
	graph g2(cin);
	cout << "second graph: " << endl;
	cout << g2 << endl;

	cout << " paths from graph 1" << endl;	
	depth_first_search dfs1(g1,0);
	print_paths(g1,dfs1);
	
	cout << " paths from graph 2" << endl;	

	depth_first_search dfs2(g2,0);
	print_paths(g2,dfs2);
	
	cout << " bfs paths from graph 1" << endl;	
	breadth_first_search bfs1(g1,0);
	print_paths(g1,bfs1);
	
	cout << " bfs paths from graph 2" << endl;	

	breadth_first_search bfs2(g2,0);
	print_paths(g2,bfs2);
	return  0;
}
