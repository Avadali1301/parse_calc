#include <iostream>
#include <string>
#include "tree.h"
using namespace std;
tree::tree() {

}
tree::~tree() {
	
}
void tree::lriot(tnode * tree){
  if(!tree) {
    return;
  }
  // both children not null because ops are binary
  // ensure not surrounding single number in parentheses
  if(tree -> left != NULL && tree -> right != NULL) {
  	in_order += "( ";
  }
  lriot(tree -> left);
  addVisitor(tree);
  lriot(tree -> right);
  if(tree -> left != NULL && tree -> right != NULL) {
  	in_order += ") ";
  }
}
void tree::lrprot(tnode * tree) {
  if(!tree) {
    return;
  }
  printVisitor(tree);
  lrprot(tree -> left);
  lrprot(tree -> right);
}
void tree::printVisitor(tnode * tree){
  cout << tree -> data << " ";
}
void tree::addVisitor(tnode * tree) {
	in_order += tree -> data;
	in_order += " ";
}
// isOperator?
bool tree::op(string exp) {
	return !exp.compare("+") || !exp.compare("-") || !exp.compare("/") || !exp.compare("*") || !exp.compare("%");
}
tree::tnode * tree::makeBet(string exp) {
	calculate c;
	stack<tnode *> s;
	int i = 0;
	int j;
	tnode * n;
	string symbol;
	while(i < exp.length()) {
		// just splitting on space
		j = c.indexOf(exp.substr(i, exp.length() - i), ' ');
		symbol = exp.substr(i, j);
		n = new tnode(symbol, NULL, NULL);
		if(op(symbol)) {
			if(s.size() > 1) {
				tnode * a = s.top();
				s.pop();
				tnode * b = s.top();
				s.pop();
				n -> right = a;
				n -> left = b;
			}
			else {
				cerr << "INVALID EXPRESSION ERROR" << endl;
				n -> data = "error";
				return n;
			}
		}
		// make sure symbol is a number
		else {
			try {
				double temp = stod(symbol);
			}
			catch(...) {
				cerr << "INVALID EXPRESSION ERROR: Symbol " << symbol <<  " neither operator nor operand" << endl;
				n -> data = "error";
				return n;
			}
		}
		s.push(n);
		i += j + 1;
	}
	// there weren't enough operators
	if(s.size() > 1) {
		cerr << "INVALID EXPRESSION ERROR" << endl;
		n -> data = "error";
		return n;
	}
	n = s.top();
	s.pop();
	return n;
}
void tree::print_in_order(tnode * tree) {
	lriot(tree);
	cout << in_order.substr(2, in_order.length() - 4) << endl;
	in_order = "";
}
void tree::execute(string exp) {
	calculate c;
	tnode * tree = makeBet(c.trimSpace(exp));
	// kick back to parseAndCalc if invalid expression
	if(!(tree -> data).compare("error")) {
		delete tree;
		return;
	}
	cout << "INFIX: ";
	print_in_order(tree);
	cout << "PREFIX: ";
	lrprot(tree);
	delete tree;
	cout << endl;
	cout << "VALUE: ";
	cout << c.rpnCalc(c.trimSpace(exp)) << endl;
}

