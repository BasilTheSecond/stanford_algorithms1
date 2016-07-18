#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort
{
public:
	MergeSort();

public:
	static std::vector<int>& sort(std::vector<int>& array);
	
private:
	static int level;
};

#endif // MERGESORT_H
