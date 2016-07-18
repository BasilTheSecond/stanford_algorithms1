#ifndef NUMBEROFINVERSIONS_H
#define NUMBEROFINVERSIONS_H

#include <vector>

class NumberOfInversions
{
public:
	NumberOfInversions();

public:
	static std::vector<int>& sort(std::vector<int>& array);
	
private:
	static int level;
};

#endif // NUMBEROFINVERSIONS_H
