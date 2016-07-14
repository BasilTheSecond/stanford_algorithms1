#include "Karatsuba.h"
#include <iostream>

//
static int count = 0;

//
std::string Karatsuba::multiply(const std::string& x, const std::string& y)
{
	count++;
	std::string ident;
	for (int i = 0; i < count; i++)
	{
		ident += " ";
	}
	//std::cout << ident << "x=" << x << "," << "y=" << y << std::endl;
	unsigned int n = std::min(x.size() / 2, y.size() / 2);
	if (n == 0)
	{
		count--;
		return multiply_one(x, y);
	}
	std::string a = first_sub(x, n);
	std::string b = second_sub(x, n);
	std::string c = first_sub(y, n);
	std::string d = second_sub(y, n);
	//std::cout << ident << "a=" << a << "," << "b=" << b
	//					<< "," << "c=" << c << "," << "d=" << d << std::endl;
	std::string z1 = Karatsuba::multiply(a, c);
	std::string z2 = Karatsuba::multiply(b, d);
	std::string z3 = Karatsuba::addition(a, b);
	std::string z4 = Karatsuba::addition(c, d);
	std::string z5 = Karatsuba::multiply(z3, z4);
	std::string z6 = Karatsuba::subtraction(z5, z1);
	std::string z7 = Karatsuba::subtraction(z6, z2);
	int n2 = 2 * n;
	std::string z8 = z1;
	for (int i = 0; i < n2; i++)
	{
		z8 = z8 + std::string("0");
	}
	std::string z9 = z7;
	for (unsigned int i = 0; i < n; i++)
	{
		z9 = z9 + std::string("0");
	}
	std::string z10 = Karatsuba::addition(z8, z9);
	std::string result = Karatsuba::addition(z10, z2);
//	if (count == 1)
//	{
//		std::cout << ident << "x=" << x << "," << "y=" << y << std::endl;
//		std::cout << ident << "a=" << a << "," << "b=" << b
//							<< "," << "c=" << c << "," << "d=" << d << std::endl;
//		std::cout << ident << "ac=" << z1 << "," << "bd=" << z2
//							<< "," << "a+b=" << z3 << "," << "c+d=" << z4
//							<< "," << "(a+b)*(c+d)=" << z5
//							<< "," << "(a+b)*(c+d)-ac=" << z6
//							<< "," << "(a+b)*(c+d)-ac-bd=" << z7 << std::endl;
//		std::cout << ident << "10^n*ac=" << z8 << "," << "10^n/2*(ad+bc)=" << z9 << std::endl;
//		std::cout << ident << "result=" << result << std::endl;
//	}
	count--;
	return result;
}

//
std::string Karatsuba::first_sub(const std::string& s, unsigned int n)
{
	if (s.size() <= n)
	{
		return std::string("");
	}
	else
	{
		return s.substr(0, s.size() - n);
	}
}

//
std::string Karatsuba::second_sub(const std::string& s, unsigned int n)
{
	if (s.size() <= n)
	{
		return s;
	}
	else
	{
		return s.substr(s.size() - n, n);
	}
}

//
std::string Karatsuba::addition(const std::string& x, const std::string& y)
{
	std::string ident;
	for (int i = 0; i < count; i++)
	{
		ident += " ";
	}
	//std::cout << ident << "addition: x=" << x << "," << "y=" << y << std::endl;
	int n = std::max(x.size(), y.size());
	std::string x1;
	std::string y1;
	for (int i = 0; i < n; i++)
	{
		x1 += std::string("0");
		y1 += std::string("0");
	}
	//std::cout << "x1=" << x1 << "," << "y1=" << y1 << std::endl;
	for (unsigned int i = 0, j = 0; j < x.size(); i++, j++)
	{
		x1.at(n - 1 - i) = x.at(x.size() - 1 - j);
	}
	for (unsigned int i = 0, j = 0; j < y.size(); i++, j++)
	{
		y1.at(n - 1 - i) = y.at(y.size() - 1 - j);
	}
	//std::cout << "x1=" << x1 << "," << "y1=" << y1 << std::endl;
	std::string result;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int a = std::stoi(x1.substr(n - i - 1, 1), nullptr, 10);
		int b = std::stoi(y1.substr(n - i - 1, 1), nullptr, 10);
		int r = a + b + c;
		std::string res = std::to_string(r);
		if (r < 10)
		{
			result = res + result;
			c = 0;
		}
		else
		{
			result = res.substr(1, 1) + result;
			c = std::stoi(res.substr(0, 1), nullptr, 10);
		}
	}
	if (c > 0)
	{
		result = std::to_string(c) + result;
	}
	//std::cout << ident << "addition: result=" << result << std::endl;
	return result;
}

//
std::string Karatsuba::multiply_one(const std::string& x, const std::string& y)
{
	if (x.size() == 1)
	{
		return multiply_one(std::stoi(x), y);
	}
	else
	{
		return multiply_one(std::stoi(y), x);
	}
}

//
std::string Karatsuba::multiply_one(int x, const std::string& y)
{
	std::string ident;
	for (int i = 0; i < count; i++)
	{
		ident += " ";
	}
	//std::cout << ident << "multiply_one: x=" << x << "," << "y=" << y << std::endl;
	std::string result("0");
	if (x > 0)
	{
		for (unsigned int i = 0; i < y.size(); i++)
		{
			int r = x * std::stoi(y.substr(y.size() - 1 - i, 1));
			std::string res = std::to_string(r);
			for (unsigned int j = 0; j < i; j++)
			{
				res += std::string("0");
			}
			result = addition(result, res);
		}
	}
	//std::cout << ident << "multiply_one: result=" << result << std::endl;
	return result;
}

//
std::string Karatsuba::subtraction(const std::string& x, const std::string& y)
{
	int n = std::max(x.size(), y.size());
	std::string x1;
	std::string y1;
	for (int i = 0; i < n; i++)
	{
		x1 += std::string("0");
		y1 += std::string("0");
	}
	for (unsigned int i = 0, j = 0; j < x.size(); i++, j++)
	{
		x1.at(n - 1 - i) = x.at(x.size() - 1 - j);
	}
	for (unsigned int i = 0, j = 0; j < y.size(); i++, j++)
	{
		y1.at(n - 1 - i) = y.at(y.size() - 1 - j);
	}
	std::string result1;
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		int a = std::stoi(x1.substr(n - i - 1, 1), nullptr, 10);
		int b = std::stoi(y1.substr(n - i - 1, 1), nullptr, 10);
		int r = a - b - c;
		if (r < 0)
		{
			r += 10;
			c = 1;
		}
		else
		{
			c = 0;
		}
		result1 = std::to_string(r) + result1;
	}
	std::string result;
	unsigned int i = 0;
	for (; i < result1.size(); i++)
	{
		if (result1.at(i) != '0')
		{
			break;
		}
	}
	result = result1.substr(i, result1.size() - i);
	return result;
}
