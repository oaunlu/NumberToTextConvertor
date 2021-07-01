#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <iomanip>
//#include <limits>
//#define STRING(num) #num		// string conversion with macro expression

using namespace std;

template <class T>
vector <int> integerToArray(T);

int count_digit(int);
int quick_pow10(int);

template <class T>
pair<string, bool> convert_to_text(T, int, int, bool);

template <class T>
pair<string, bool> basamaak(T, int, bool, int);

int main()	// driver code
{

	cout << "Sayi-Yazi Cevirme aracina hosgeldiniz!!\n"
		    "Su anda sistemimiz 999 trilyona kadar olan sayilari cevirebilmektedir.\n"
			"Noktadan sonraki hassasiyet yuksek sayilarda bozuldugu icin 2 olarak sinirlandirilmistir.\n"
			"Yazim bicimi: [Tamsayi]'.'[Ondalik] araya virgul koymayiniz :)\n"
			"Ornek: 123456.12 -> yuzyirmiucbindortyuzellialtinoktaoniki\n"
		    "			Yazar: Orkun Alp Unlu		Versiyon:1.3\n\n";

	while (true) // superloop
	{
		long double input;

		cout << "Lutfen ondalikli bir sayi giriniz\n";
		cin >> input;

		stringstream ss;
		ss << fixed << setprecision(/*numeric_limits<float>::max()*/2) << input; // string conversion with stringsream
		string strinpt = ss.str();

		//string strinpt = to_string(input); // string conversion with std::to_string() function

		//string strinpt(STRING(input));	// string conversion with macro expression

		string str1 = strinpt.substr(0, strinpt.find("."));
		string str2 = strinpt.substr(strinpt.find(".") + 1);

		//cout << str1 << endl << str2 << endl;

		long long input1 = stoll(str1);
		long input2 = stol(str2);

		string output = "";

		vector <int> intArr1 = integerToArray<long long>(input1);
		vector <int> intArr2 = integerToArray<long>(input2);

		long n1 = intArr1.size();
		bool isUpperBasamak = false;
		for (unsigned i = 0; i < intArr1.size(); i++)
		{
			pair<string, bool> returnVals = convert_to_text<long long>(input1, intArr1[i], n1, isUpperBasamak);
			output += returnVals.first;
			isUpperBasamak = returnVals.second;
			n1--;
		}

		if (input2 != 0)
		{
			output += "nokta";

			long n2 = intArr2.size();
			bool isUpperBasamak = false;
			for (unsigned i = 0; i < intArr2.size(); i++)
			{
				pair<string, bool> returnVals = convert_to_text<long>(input2, intArr2[i], n2, isUpperBasamak);
				output += returnVals.first;
				isUpperBasamak = returnVals.second;
				n2--;
			}
		}
		cout << output << endl;

		string exitInput;

		cout << "Devam etmek istiyor musunuz?\n evet/hayir\n";
		cin >> exitInput;

		if (exitInput == "hayir")
			break;
		else
			continue;
	}
	return 0;
}

template <class T>	//template function for text conversion
pair<string, bool> convert_to_text(T input, int number, int basamaksayisi, bool isUpperBasamak) {
	pair<string, bool> returnVals;
	string output = "";
	int basamak = basamaksayisi % 3;

	if (basamaksayisi > 3)
	{
		switch (basamak)
		{
		case 0:
		{
			returnVals = basamaak(input, number, isUpperBasamak, 3);
			return returnVals;
		}
		case 1:
		{
			if (basamaksayisi != 4)
			{
				if (number != 0)
				{
					returnVals = convert_to_text(input, number, 1, false);
					output = returnVals.first;
					switch (basamaksayisi)
					{
					case 7:
						output += "milyon";
						break;
					case 10:
						output += "milyar";
						break;
					case 13:
						output += "trilyon";
						break;
					}
				}
				else if (number == 0 && isUpperBasamak)
				{
					switch (basamaksayisi)
					{
					case 7:
						output += "milyon";
						break;
					case 10:
						output += "milyar";
						break;
					case 13:
						output += "trilyon";
						break;
					}
					isUpperBasamak = false;
				}

				return make_pair(output, false);
			}
			else
			{
				if (number != 0)
				{
					if (number != 1)
					{
						returnVals = convert_to_text(input, number, 1, false);
						output = returnVals.first;
					}

					output += "bin";
				}
				else if (number == 0 && isUpperBasamak)
				{
					output += "bin";
					isUpperBasamak = false;
				}

				return make_pair(output, false);
			}
		}
		case 2:
		{
			returnVals = basamaak(input, number, isUpperBasamak, 2);
			return returnVals;
		}
		}
	}
	else
	{
		switch (basamaksayisi)
		{
		case 1:
			switch (number)
			{
			case 0:
				return make_pair("", false);
			case 1:
				return make_pair("bir", false);
			case 2:
				return make_pair("iki", false);
			case 3:
				return make_pair("uc", false);
			case 4:
				return make_pair("dort", false);
			case 5:
				return make_pair("bes", false);
			case 6:
				return make_pair("alti", false);
			case 7:
				return make_pair("yedi", false);
			case 8:
				return make_pair("sekiz", false);
			case 9:
				return make_pair("dokuz", false);
			}
		case 2:
			switch (number)
			{
			case 0:
				return make_pair("", false);
			case 1:
				return make_pair("on", false);
			case 2:
				return make_pair("yirmi", false);
			case 3:
				return make_pair("otuz", false);
			case 4:
				return make_pair("kirk", false);
			case 5:
				return make_pair("elli", false);
			case 6:
				return make_pair("altmis", false);
			case 7:
				return make_pair("yetmis", false);
			case 8:
				return make_pair("seksen", false);
			case 9:
				return make_pair("doksan", false);
			}
		case 3:
		{
			if (number != 0)
			{
				if (number != 1)
				{
					returnVals = convert_to_text(input, number, 1, false);
					output = returnVals.first;
				}

				output += "yuz";
			}
			return make_pair(output, false);
		}
		}
	}
	return make_pair("", false);
}

template <class T>
pair<string, bool> basamaak(T input ,int number, bool isUpperBasamak, int i)
{
	pair<string, bool> returnVals;
	string output = "";

	if (number != 0)
	{
		returnVals = convert_to_text(input, number, i, false);
		output = returnVals.first;
		isUpperBasamak = true;
	}

	return make_pair(output, isUpperBasamak);
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