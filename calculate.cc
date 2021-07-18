#include <iostream>
#include <cstdlib>
#include "calculate.h"
#include <string>
using namespace std;

calculate::calculate() {

}
calculate::~calculate() {

}
// no consecutive spaces 
string calculate::trimSpace(string exp) {
	string output = "";
	int j = 0;
	while(exp[j] == ' ') {
		j++;	}
	for(int i = j; i < exp.length() - 1; i++) {
		if(!(exp[i] == ' ' && exp[i + 1] == ' ')) {
			output += exp[i];
		}
	}
	if(exp[exp.length() - 1] != ' ') {
		output += exp[exp.length() - 1];
	}
	return output;
}
int calculate::indexOf(string s, char a) {
	int i = 0;
	while(s[i] != a && i < s.length()) {
		i += 1;
	}
	// returns s.length() if char not in string
	return i;
}
// evaluates postfix expression
// spaces are delimiters
string calculate::rpnCalc(string exp) {
	stack<string> s;
	int i = 0;
	int j;
	string symbol;
	while(i < exp.length()) {
		j = indexOf(exp.substr(i, exp.length() - i), ' ');
		symbol = exp.substr(i, j);
		string a_1;
		string b_1;
		double a;
		double b;
		bool popped = false;
		if(s.size() > 1) {
			a_1 = s.top();
			s.pop();
			a = stod(a_1);
			b_1 = s.top();
			s.pop();
			b = stod(b_1);
			popped = true;
		}
		// check if string contains '.' to see if double
		if(!symbol.compare("+")) {
			if(indexOf(a_1, '.') == a_1.length() && indexOf(b_1, '.') == b_1.length()) {
				s.push(to_string((int)b + (int)a));
			}
			else {
				s.push(to_string(b + a));
			}
		}
		else if(!symbol.compare("-")) {
			if(indexOf(a_1, '.') == a_1.length() && indexOf(b_1, '.') == b_1.length()) {
				s.push(to_string((int)b - (int)a));
			}
			else {
				s.push(to_string(b - a));
			}
		}
		else if(!symbol.compare("*")) {
			if(indexOf(a_1, '.') == a_1.length() && indexOf(b_1, '.') == b_1.length()) {
				s.push(to_string((int)b * (int)a));
			}
			else {
				s.push(to_string(b * a));
			}
		}
		// changes based on double vs int
		else if(!symbol.compare("/")) {
			if(a == 0) {
				s.push("ERROR: Division by 0");
				break;
			}
			if(indexOf(a_1, '.') == a_1.length() && indexOf(b_1, '.') == b_1.length()) {
				s.push(to_string((int)b / (int)a));
			}
			else {
				s.push(to_string(b / a));
			}

		}
		else if(!symbol.compare("%")) {
			if(a == 0) {
				s.push("ERROR: Division by 0");
				break;
			}
			if(indexOf(a_1, '.') == a_1.length() && indexOf(b_1, '.') == b_1.length()) {
				s.push(to_string((int)b % (int)a));
			}
			else {
				s.push(to_string(fmod(b, a)));
			}
		}
		else {
			if(popped) {
				s.push(b_1);
				s.push(a_1);
			}
			s.push(symbol);
		}
		// jump to start of next symbol
		i += j + 1;
	}
	return s.top();
}



