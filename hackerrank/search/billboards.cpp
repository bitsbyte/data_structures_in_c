#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ul;

ul get_max_profit(vector<int> &profits, int K)
{
	vector<ul> first_row(K+1);
	vector<ul> second_row(K+1);
	ul max_prev_row, max_curr_row;
	
	vector<ul> *temp;
	vector<ul> *first = &first_row;
	vector<ul> *second = &second_row;
	int N = profits.size();	

	first_row[0] = 0;
	for(int j = 1 ; j <= K ; ++j )
		first_row[j] = profits[0];

	
	max_curr_row = max_prev_row = profits[0];
	for(int row = 2; row <= N ; ++row)
	{
		(*second)[0] = max_prev_row;
		max_curr_row = max_prev_row;
		for(int col = 1; col <= K ; ++col)
		{
			(*second)[col] = (*first)[col-1] + profits[row-1];
			if( max_curr_row < (*second)[col] )
				max_curr_row = (*second)[col];
		}
				
		max_prev_row = max_curr_row;
		temp = first;
		first = second;
		second = temp; 
	}
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
