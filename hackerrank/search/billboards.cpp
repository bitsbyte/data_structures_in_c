#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ul;

ul get_max_profit(vector<int> &profits, int K)
{
	vector<ul> first_row(K+1);
	vector<ul> second_row(K+1);
	ul max_prev_row, max_curr_row;
	int N = profits.size();	

	first_row[0] = 0;
	for(int j = 1 ; j <= K ; ++j )
		first_row[j] = profits[0];

	
	max_curr_row = max_prev_row = profits[0];
	for(int row = 2; row <= N ; ++row)
	{
		second_row[0] = max_prev_row;
		max_curr_row = second_row[0];
		for(int col = 1; col <= K ; ++col)
		{
			second_row[col] = first_row[col-1] + profits[row-1];
			if(max_curr_row < second_row[col])
				max_curr_row = second_row[col];	
		}
				
		max_prev_row = max_curr_row;
		first_row = second_row;
	}
	/* // this code is unnecessary, max_curr_row already holds ans
	ul max_profit = 0;
	for(int j = 0 ; j <= K ; ++j)
	{
		if( max_profit < second_row[j])
			max_profit = second_row[j];	
	}

	return max_profit;	
	*/
	return max_curr_row;
}


int main()
{
	int N,K;
	vector<int> profits;

	cin >>  N >> K;	

	for(int i = 0 ; i < N ; ++i)
	{
		int profit ;
		cin >> profit;
		profits.push_back(profit);
	}
	
	cout << get_max_profit(profits, K) << endl;
	return 0;
}
