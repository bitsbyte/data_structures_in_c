#include "bit.h"
#include <iostream>

using namespace std;

void print_bit(bit<int> &t)
{
	cout << "bit : \n" ;
	for(int i = 0 ; i < t.size(); ++i)
		cout << t[i] << " " ;
	cout << endl;
}

int main()
{
	bit<int> t;

	int a[] = {1,2,3,4,3,2};
	cout << "a : " << endl;
	for(int i = 0 ; i < 6 ; ++i)
		cout << a[i] << " " ;
	cout << endl;	

	for(int i = 0 ; i < 6 ; ++i)
		t.insert(a[i]);

	cout << "cf : "; 
	int cf = 0;
	for(int i = 0 ; i < 6 ; ++i)
	{
		cf += a[i];
		cout << cf << " " ;
	}
	cout << endl;
	print_bit(t);

	cout << "update a[3] = 8" << endl;
	t.update(3,8);
	print_bit(t);

	cout << "update a[0] = 2" << endl;
	t.update(0,2);
	print_bit(t);	
	

	return 0;
}

