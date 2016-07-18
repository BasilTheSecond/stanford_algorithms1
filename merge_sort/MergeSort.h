#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort
{
public:
	MergeSort();

public:
	static std::vector<int>& merge(const std::vector<int>& array, std::vector<int>& result);
	
private:
	static int level;
};

#endif // MERGESORT_H
