#include <iostream>
#include <cstdlib>
#include <string>
#include "calculate.h"
using namespace std;
class tree {
	private:
		string in_order;
	public:
		struct tnode {
			string data;
			tnode * left;
			tnode * right;
			tnode(string data, tnode *left, tnode *right): 
			data(data), left(left), right(right) {}
		};
		tree();
		~tree();
		void lriot(tnode * tree);
		void lrprot(tnode * tree);
		void printVisitor(tnode * tree);
		void addVisitor(tnode * tree);
		bool op(string exp);
		tnode * makeBet(string exp);
		void print_in_order(tnode * tree);
		void execute(string exp);
};