#include <iostream>
#include <cstdlib>
#include <string>
#include "stack.cc"
using namespace std;
class calculate {
	public:
		calculate();
		~calculate();
		int indexOf(string s, char a);
		string rpnCalc(string exp);
		string trimSpace(string exp);
};