#include <iostream>
#include <vector>
#include <string>
//#include <sstream>
//#include <iomanip>
//#include <limits>

using namespace std;

template <class T>
vector <int> integerToArray(T);

int count_digit(int);
int quick_pow10(int);

template <class T>
string convert_to_text(T, int, int, bool);

int main()	//driver code
{

	cout << "Sayi-Yazi Cevirme aracina hosgeldiniz!!\n";
	cout << "Su anda sistemimiz 100 trilyona kadar olan sayilari cevirebilmektedir.\n";
	cout << "			Yazar: Orkun Alp Unlu		Versiyon:1.0\n\n";

    while(true) //superloop
    {
    	double input;
    	
    	cout << "Lutfen ondalikli bir sayi giriniz\n";
    	cin >> input;
    
    	//stringstream ss;
    
    	//ss << fixed << setprecision(numeric_limits<float>::max()) << input;
    
    	//ss << input;
    	//string strinpt = ss.str();
    
    	string strinpt = to_string(input);
    
    	string str1 = strinpt.substr(0, strinpt.find("."));
    	string str2 = strinpt.substr(strinpt.find(".")+1);
    	
    	//cout << str1 << endl << str2 << endl;
    
    	long long input1 = stoll(str1);
    	int input2 = stoi(str2);
    
    	string output = "";
    
    	vector <int> intArr1 = integerToArray<long long>(input1);
    	vector <int> intArr2 = integerToArray<int>(input2);
    
    	int n1 = intArr1.size();
    
    	for (unsigned i = 0; i < intArr1.size(); i++)
    	{
    		output += convert_to_text<long long>(input1, intArr1[i], n1, false);
    		n1--;
    	}
    
    	output += "virgul";
    
    	int n2 = intArr2.size();
    
    	for (unsigned i = 0; i < intArr2.size(); i++)
    	{
    		output += convert_to_text<int>(input2, intArr2[i], n2, false);
    		n2--;
    	}
    
    	cout << output << endl;
    	
    	string exitInput;
    	
    	cout << "Devam etmek istiyor musunuz?\n evet/hayir\n";
    	cin >> exitInput;
    	
    	if(exitInput=="hayir")
    	    break;
    	else
    	    continue;
    }
	return 0;
}


template <class T>	//template function for text conversion
string convert_to_text(T input, int number, int basamaksayisi, bool isUpperBasamak) {
	switch (basamaksayisi)
	{
	case 1:
		switch (number)
		{
		case 0:
			return "";
		case 1:
			return "bir";
		case 2:
			return "iki";
		case 3:
			return "uc";
		case 4:
			return "dort";
		case 5:
			return "bes";
		case 6:
			return "alti";
		case 7:
			return "yedi";
		case 8:
			return "sekiz";
		case 9:
			return "dokuz";
		}
	case 2:
		switch (number)
		{
		case 0:
			return "";
		case 1:
			return "on";
		case 2:
			return "yirmi";
		case 3:
			return "otuz";
		case 4:
			return "kirk";
		case 5:
			return "elli";
		case 6:
			return "altmis";
		case 7:
			return "yetmis";
		case 8:
			return "seksen";
		case 9:
			return "doksan";
		}
	case 3:
	{
		string hundreds = "";
		if (number != 0)
		{
			if (number != 1)
				hundreds = convert_to_text(input, number, 1, false);

			hundreds += "yuz";
		}
		return hundreds;
	}
	case 4:
	{
		string thousands = "";
		if (number != 0)
		{
			if (number != 1)
				thousands = convert_to_text(input, number, 1, false);

			thousands += "bin";
		}
		else if (number == 0 && isUpperBasamak)
		{
			thousands += "bin";
			isUpperBasamak = false;
		}
		return thousands;
	}
	case 5:
	{
		string tenthousands = "";
		if (number != 0)
		{
			tenthousands = convert_to_text(input, number, 2, false);

		}
		isUpperBasamak = true;
		return tenthousands;
	}
	case 6:
	{
		string hundredthousands = "";
		if (number != 0)
		{
			hundredthousands = convert_to_text(input, number, 3, false);
		}
		isUpperBasamak = true;
		return hundredthousands;
	}
	case 7:
	{
		string millions = "";
		if (number != 0)
		{
			millions = convert_to_text(input, number, 1, false);

			millions += "milyon";
		}
		else if (number == 0 && isUpperBasamak)
		{
			millions += "milyon";
			isUpperBasamak = false;
		}
		return millions;
	}
	case 8:
	{	string tenmillions = "";
		if (number != 0)
		{
			tenmillions = convert_to_text(input, number, 2, false);

		}
		isUpperBasamak = true;
		return tenmillions;
	}
	case 9:
	{	string hundredmillions = "";
		if (number != 0)
		{
			hundredmillions = convert_to_text(input, number, 3, false);
		}
		isUpperBasamak = true;
		return hundredmillions;
	}
	case 10:
	{
		string billions = "";
		if (number != 0)
		{
			billions = convert_to_text(input, number, 1, false);

			billions += "milyar";
		}
		else if (number == 0 && isUpperBasamak)
		{
			billions += "milyar";
			isUpperBasamak = false;
		}
		return billions;
	}
	case 11:
	{	string tenbillions = "";
		if (number != 0)
		{
			tenbillions = convert_to_text(input, number, 2, false);

		}
		isUpperBasamak = true;
		return tenbillions;
	}
	case 12:
	{	
		string hundredbillions = "";
		if (number != 0)
		{
			hundredbillions = convert_to_text(input, number, 3, false);
		}
		isUpperBasamak = true;
		return hundredbillions;
	}
	case 13:
	{
		string trillions = "";
		if (number != 0)
		{
			trillions = convert_to_text(input, number, 1, false);

			trillions += "trilyon";
		}
		else if (number == 0 && isUpperBasamak)
		{
			trillions += "trilyon";
			isUpperBasamak = false;
		}
		return trillions;
	}
	case 14:
	{	string tentrillions = "";
	if (number != 0)
	{
		tentrillions = convert_to_text(input, number, 2, false);

	}
	isUpperBasamak = true;
	return tentrillions;
	}
	case 15:
	{
		string hundredtrillions = "";
		if (number != 0)
		{
			hundredtrillions = convert_to_text(input, number, 3, false);
		}
		isUpperBasamak = true;
		return hundredtrillions;
	}
}
	return "";
}

template <class T>
vector <int> integerToArray(T x)
{
	vector <int> resultArray;
	while (true)
	{
		resultArray.insert(resultArray.begin(), x % 10);
		x /= 10;
		if (x == 0)
			return resultArray;
	}
}

int count_digit(int number) {
	int count = 0;

	while (number != 0) {
		number = number / 10;
		count++;
	}

	return count;
}

int quick_pow10(int n)
{
	static int pow10[10] = {
		1, 10, 100, 1000, 10000,
		100000, 1000000, 10000000, 100000000, 1000000000
	};

	return pow10[n];
}
