#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct task
{
    int di;
    int mi;
} task;

class compare_task
{
	public:
		bool operator()(task i, task j)
		{
			return (i.di > j.di);
		}
};

typedef priority_queue<task, vector<task>, compare_task>  taskqueue;


int getMinMax(taskqueue  q)
{
   
		int max_overshoot = 0;
		int next_begin = 0;
		int current_overshoot;

		while(!q.empty())
		{
			task t = q.top();
			q.pop();
			next_begin = next_begin + t.mi;
			current_overshoot = next_begin - t.di;
			if( current_overshoot > max_overshoot )
				max_overshoot = current_overshoot;
		}
		 
		return max_overshoot;
}

void print_q(taskqueue q)
{
	cout << "queue: "  ;
	while(!q.empty())
	{
		task t = q.top();
		q.pop();
		cout << t.di << " " ;
	}
	cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
		taskqueue input;   
		int T;
	
		cin >> T; 
    while(T--)
    {
        task t;
        cin >> t.di >> t.mi;
				input.push(t);
				//print_q(input);
				cout << getMinMax(input) << endl;
    }
  
    return 0;
}

