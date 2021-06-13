/*#include <iostream>
//#include <math.h>
#include <vector>

using namespace std;

int count_digit(int);
string convert_to_text(int, int, int);
int quick_pow10(int);
//vector <int> integerToArray(int);

int main()
{
	int input;
	int digcount;
	int remainder;

	string output = "";

	cout << "Enter a number\n";
	cin >> input;

	//vector <int> intArr = integerToArray(input);

	//reverse(intArr.begin(), intArr.end());

	//int n = intArr.size();

	//for (unsigned i = 0; i < intArr.size(); i++)
	//{
	//	output += convert_to_text(input, intArr[i], n);
	//	n--;
	//}

	digcount = count_digit(input);

	int i = 1;
	int basamaksay�s� = digcount;

	while (digcount >= i)
	{
		int basamak = (input / quick_pow10(digcount - i)) % 10;
		output += convert_to_text(input, basamak, basamaksay�s�);
		input = input - quick_pow10(digcount - i);
		i++;
		basamaksay�s�--;
	}

	cout << output << endl;

	return 0;
}

//vector <int> integerToArray(int x)
//{
//	vector <int> resultArray;
//	while (true)
//	{
//		resultArray.insert(resultArray.begin(), x % 10);
//		x /= 10;
//		if (x == 0)
//			return resultArray;
//	}
//}

int count_digit(int number) {
	int count = 0;

	while (number != 0) {
		number = number / 10;
		count++;
	}

	return count;
}

string convert_to_text(int input,int number, int basamaksay�s�) {
	if (basamaksay�s� == 1)
	{
		switch (number)
		{
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		}
	}
	else if (basamaksay�s� == 2)
	{
		switch (number)
		{
		case 1:
			return "ten";
		case 2:
			return "twenty";
		case 3:
			return "thirty";
		case 4:
			return "forty";
		case 5:
			return "fifty";
		case 6:
			return "sixty";
		case 7:
			return "seventy";
		case 8:
			return "eighty";
		case 9:
			return "ninety";
		}
	}
	else if (basamaksay�s� == 3)
	{
		string hundreds = "";
		if (number != 1)
			hundreds = convert_to_text(input, number, 1);

		hundreds += "hundred";
		return hundreds;
	}
	else if (basamaksay�s� > 3 && basamaksay�s� <= 6)
	{
		string thousands = "";

		int nnumber = input / 1000;
		int basamaksay�s�1 = count_digit(nnumber);
		int i = 1;
			if (number != 1)
				thousands += convert_to_text(input, number, basamaksay�s�1);
			input = input - quick_pow10(basamaksay�s� - i);
			basamaksay�s�1--;
			i++;
		if(basamaksay�s�1==0)
			thousands += "thousand";
		return thousands;
	}
	else if (basamaksay�s� > 6 && basamaksay�s� <= 9)
	{
		string millions = "";

		int nnumber = input / 1000000;
		int basamaksay�s�1 = count_digit(nnumber);
		int i = 1;
			millions += convert_to_text(input, number, basamaksay�s�1);
			input = input - quick_pow10(basamaksay�s� - i);
			basamaksay�s�1--;
			i++;
		if(basamaksay�s�1==0)
			millions += "milyon";
		return millions;
	}
}

int quick_pow10(int n)
{
	static int pow10[10] = {
		1, 10, 100, 1000, 10000,
		100000, 1000000, 10000000, 100000000, 1000000000
	};

	return pow10[n];
}
*/