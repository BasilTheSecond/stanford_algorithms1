#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort
{
public:
	MergeSort();

public:
	static void merge(const std::vector<int>& array, std::vector<int>& result);
};

#endif // MERGESORT_H
