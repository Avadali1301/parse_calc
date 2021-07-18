#include "tree.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	string exp = "";
	while(exp.compare("q")) {
		cout << "Enter postfix expression (enter 'q' to terminate program): ";
		getline(cin, exp);
		if(!exp.compare("q")) {
			break;
		}
		tree t;
		t.execute(exp);
	}
}