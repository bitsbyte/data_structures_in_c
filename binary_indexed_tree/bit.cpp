#include "bit.h"

template <class T>
void bit<T>::update(int index, T freq)
{

}

template <class T>
void bit<T>::insert(T freq)
{
	frequency.push_back(freq);
	// update partial_frequency
	int last_index = frequency.size() - 1;
	int begin = last_index - (last_index & -last_index);
	T sum = frequency[begin++];
	for(int i = begin ; i <= last_index ; ++i)
	{
		sum += frequency[i];
	}
	partial_frequency.push_back(sum);
}

template <class T>
T bit<T>::read(int index)
{
	T cumulative_freq = partial_frequency[0];
	while(index)
	{
		cumulative_freq += partial_frequency[index];
		// remove least significant 1 bit
		index = index - (index & (-index));	
	}
	return cumulative_freq;
}

template <class T>
T bit<T>::operator[](int index)
{
	return read(index);
}

template <class T>
int bit<T>::size()
{
	return frequency.size();
}
