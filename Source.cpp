#include "convertor.h"
#include <chrono>
//#include <limits>
//#define STRING(num) #num		// string conversion with macro expression

using namespace std;
using namespace std::chrono;

int main()	// driver code
{

	cout << "Sayi-Yazi Cevirme aracina hosgeldiniz!!\n"
		    "Su anda sistemimiz 999 trilyona kadar olan sayilari cevirebilmektedir.\n"
			"Noktadan sonraki hassasiyet yuksek sayilarda bozuldugu icin 2 olarak sinirlandirilmistir.\n"
			"Yazim bicimi: [Tamsayi]'.'[Ondalik] araya virgul koymayiniz :)\n"
			"Ornek: 123456.12 -> yuzyirmiucbindortyuzellialtinoktaoniki\n"
		    "			Yazar: Orkun Alp Unlu		Versiyon:1.5\n\n";

	while (true) // superloop
	{
		long double input;

		cout << "Lutfen ondalikli bir sayi giriniz\n";
		cin >> input;

		high_resolution_clock::time_point start = high_resolution_clock::now();

		convertor* c = new convertor(input);

		high_resolution_clock::time_point stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start).count();
		cout << duration << " mikro saniyede bitti." << endl;
		
		delete c;

		string exitInput;
		cin >> exitInput;

		if (exitInput == "hayir")
			break;
		else
			continue;
	}
	return 0;
}