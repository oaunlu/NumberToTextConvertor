#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <iomanip>

using namespace std;

class convertor
{
public:
	convertor(long double);
	~convertor();

	template <class T>
	vector <int> integerToArray(T);

	int count_digit(int);
	int quick_pow10(int);

	template <class T>
	pair<string, bool> convert_to_text(T, int, int, bool);

	template <class T>
	pair<string, bool> basamaak(T, int, bool, int);
};

