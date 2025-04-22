#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
    const unsigned int n = v.size();
	if (n < 2) return;

    for(unsigned int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
		
        for(unsigned int j = 0; j < n - i - 1; j++)
        {
            if(v[j] > v[j + 1])
			{
				// swap:
				T tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
    }
}

template<Sortable T>
void HeapSort(std::vector<T>& v)
{

    const unsigned int n = v.size();

    for(int i = n/2 - 1; i >= 0; i--){
		heapify(v, n, i);
		}
		
	for (int i = n - 1; i > 0; i--)	{
		std::swap(v[0], v[i]);
		heapify(v, i, 0);
	}
}

template<Sortable T>
void heapify(std::vector<T>& v, unsigned int n, unsigned int i)
{
	unsigned int largest = i;
	unsigned int left = 2 * i + 1;
	unsigned int right = 2 * i + 2;
	
	if(left < n && v[left] > v[largest]){
		largest = left;
	}
	if(right < n && v[right] > v[largest]){
		largest = right;
	} 
	if (largest != i){
		std::swap(v[i],v[largest]);
		heapify(v, n, largest);
	}
}

}

