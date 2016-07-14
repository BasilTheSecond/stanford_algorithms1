#ifndef KARATSUBA_H
#define KARATSUBA_H

#include <string>

class Karatsuba
{
public:
	static std::string multiply(const std::string& x, const std::string& y);

private:
	static std::string first_sub(const std::string& s, unsigned int n);
	static std::string second_sub(const std::string& s, unsigned int n);
	static std::string addition(const std::string& x, const std::string& y);
	static std::string multiply_one(const std::string& x, const std::string& y);
	static std::string multiply_one(int x, const std::string& y);
	static std::string subtraction(const std::string& x, const std::string& y);
};

#endif // KARATSUBA_H
