#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
typedef struct task
{
    int di;
    int mi;
} task;

vector<task> input;

int compare_task(task i, task j)
{
    return (i.di < j.di);
}

void print_task(int size)
{
    for(int i =0 ; i < size ; ++i)
        cout << input[i].di << " ";
    cout << endl;
}

int getMinMax(int size)
{
    sort(input.begin(), input.begin()+size, compare_task);
//    print_task(size);
   
		int max_overshoot = 0;
		int next_begin = 0;
		int current_overshoot;

		for(int i = 0 ; i < size ; ++i)
		{
			next_begin = next_begin + input[i].mi;
			current_overshoot = next_begin - input[i].di;
			if( current_overshoot > max_overshoot )
				max_overshoot = current_overshoot;
		}
		 
		return max_overshoot;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,di,mi;
    
    cin >> T;
    i = T;
    
    while(i--)
    {
        task t;
        cin >> t.di >> t.mi;
        input.push_back(t);
    }
  
	for(int i = 1 ; i <= input.size(); ++i)  
	 	cout << getMinMax(i) << endl;   
    
    return 0;
}

