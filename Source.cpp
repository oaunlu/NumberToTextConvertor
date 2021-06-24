#include <iostream>
#include <vector>
#include <string>
#include <utility>
//#include <sstream>
//#include <iomanip>
//#include <limits>

using namespace std;

template <class T>
vector <int> integerToArray(T);

int count_digit(int);
int quick_pow10(int);

template <class T>
pair<string, bool> convert_to_text(T, int, int, bool);

int main()	//driver code
{

	cout << "Sayi-Yazi Cevirme aracina hosgeldiniz!!\n"
		    "Su anda sistemimiz 999 trilyona kadar olan sayilari cevirebilmektedir.\n"
			"Yazim bicimi: [Tamsayi]'.'[Ondalik] araya virgul koymayiniz :)\n"
			"Ornek: 123456.123456 -> yuzyirmiucbindortyuzellialtinoktayuzyirmiucbindortyuzellialti\n"
		    "			Yazar: Orkun Alp Unlu		Versiyon:1.2\n\n";

	while (true) //superloop
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
		string str2 = strinpt.substr(strinpt.find(".") + 1);

		//cout << str1 << endl << str2 << endl;

		long long input1 = stoll(str1);
		int input2 = stoi(str2);

		string output = "";

		vector <int> intArr1 = integerToArray<long long>(input1);
		vector <int> intArr2 = integerToArray<int>(input2);

		int n1 = intArr1.size();
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

			int n2 = intArr2.size();
			bool isUpperBasamak = false;
			for (unsigned i = 0; i < intArr2.size(); i++)
			{
				pair<string, bool> returnVals = convert_to_text<int>(input2, intArr2[i], n2, isUpperBasamak);
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
		pair<string, bool> returnVals;
		string hundreds = "";
		if (number != 0)
		{
			if (number != 1)
			{
				returnVals = convert_to_text(input, number, 1, false);
				hundreds = returnVals.first;
			}

			hundreds += "yuz";
		}

		return make_pair(hundreds, false);
	}
	case 4:
	{
		pair<string, bool> returnVals;
		string thousands = "";
		if (number != 0)
		{
			if (number != 1)
			{
				returnVals = convert_to_text(input, number, 1, false);
				thousands = returnVals.first;
			}

			thousands += "bin";
		}
		else if (number == 0 && isUpperBasamak)
		{
			thousands += "bin";
			isUpperBasamak = false;
		}

		return make_pair(thousands, false);
	}
	case 5:
	{
		pair<string, bool> returnVals;
		string tenthousands = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 2, false);
			tenthousands = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(tenthousands, isUpperBasamak);
	}
	case 6:
	{
		pair<string, bool> returnVals;
		string hundredthousands = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 3, false);
			hundredthousands = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(hundredthousands, isUpperBasamak);
	}
	case 7:
	{
		pair<string, bool> returnVals;
		string millions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 1, false);
			millions = returnVals.first;
			millions += "milyon";
		}
		else if (number == 0 && isUpperBasamak)
		{
			millions += "milyon";
			isUpperBasamak = false;
		}

		return make_pair(millions, false);
	}
	case 8:
	{
		pair<string, bool> returnVals;
		string tenmillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 2, false);
			tenmillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(tenmillions, isUpperBasamak);
	}
	case 9:
	{
		pair<string, bool> returnVals;
		string hundredmillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 3, false);
			hundredmillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(hundredmillions, isUpperBasamak);
	}
	case 10:
	{
		pair<string, bool> returnVals;
		string billions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 1, false);
			billions = returnVals.first;
			billions += "milyar";
		}
		else if (number == 0 && isUpperBasamak)
		{
			billions += "milyar";
			isUpperBasamak = false;
		}

		return make_pair(billions, false);
	}
	case 11:
	{
		pair<string, bool> returnVals;
		string tenbillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 2, false);
			tenbillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(tenbillions, isUpperBasamak);
	}
	case 12:
	{
		pair<string, bool> returnVals;
		string hundredbillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 3, false);
			hundredbillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(hundredbillions, isUpperBasamak);
	}
	case 13:
	{
		pair<string, bool> returnVals;
		string trillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 1, false);
			trillions = returnVals.first;
			trillions += "trilyon";
		}
		else if (number == 0 && isUpperBasamak)
		{
			trillions += "trilyon";
			isUpperBasamak = false;
		}

		return make_pair(trillions, false);
	}
	case 14:
	{
		pair<string, bool> returnVals;
		string tentrillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 2, false);
			tentrillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(tentrillions, isUpperBasamak);
	}
	case 15:
	{
		pair<string, bool> returnVals;
		string hundredtrillions = "";
		if (number != 0)
		{
			returnVals = convert_to_text(input, number, 3, false);
			hundredtrillions = returnVals.first;
			isUpperBasamak = true;
		}

		return make_pair(hundredtrillions, isUpperBasamak);
	}
	}
	return make_pair("", false);
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