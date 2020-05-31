#include <iostream>
#include <typeinfo>
#include <string>
#include "table.h"
#include <stdio.h> 
#include <time.h>
#include "ConvFunction.h"

using namespace std;
class PosNumber {
	int posNumber;
public:
	PosNumber(int num) :posNumber(num) {
		if (num < 0)
			throw exception("negative number");
	}
};
int main()
{
	HashTable<string, int> convtest(10);
	convtest.Add("Vadim", 19);
	convtest.Add("Katya", 20);
	cout << convtest.Find("Katya") << endl;
	system("pause");
}
