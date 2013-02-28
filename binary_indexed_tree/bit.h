#ifndef _BIT_H
#define _BIT_H

#include  <vector>
/* Binary Indexed Tree */

template <class T>
class bit 
{

public:
	void	update(int index, T freq);
	void 	insert(T freq);
	T	 	 	read(int index); /* read(..) and [] are same */	
	T 		operator [](int index);
	int		size();
	
private:
	std::vector<T> frequency;
	std::vector<T> partial_frequency;	
};


template <class T>
void bit<T>::update(int index, T freq)
{
	if( index == 0)
	{
		frequency[0] = partial_frequency[0] = freq;
		return;
	}
	
	int change = freq - frequency[index];
	frequency[index] = freq;
	while( index < frequency.size()) 
	{
		partial_frequency[index] += change;
		index += (index & -index);
	}
}

template <class T>
void bit<T>::insert(T freq)
{
  frequency.push_back(freq);
  // update partial_frequency
  int last_index = frequency.size() - 1;
	T 	sum;
	
	if(frequency.size() > 1)
	{ 
  	int begin = 1+last_index - (last_index & -last_index);
		sum = frequency[begin];
  	for(int i = ++begin ; i <= last_index ; ++i)
  	{
   	 sum += frequency[i];
  	}
  }
	else
		sum = frequency[0];

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
    index = index - (index & -index);   
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

#endif
