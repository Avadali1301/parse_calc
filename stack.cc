#include <iostream>
#include <cstdlib>
using namespace std;

template<typename stackData> 
class stack{
	public:
		stack();				//Constructs an empty stack.
		~stack();				//Removes & deletes all remaining elements of the stack.
		void push(stackData d);  //Creates a node in the stack and places d as the data in it.
		void pop();				//Removes and deletes the top node from the stack.
		
		stackData top() const;	//Returns the data stored in the top node of the stack.
		size_t size() const;	//Returns the number of nodes in the stack.
		bool empty() const;		//Returns whether the stack is empty.
		void print() const;	//Prints out a visual representation of the stack.

	private:
		struct Node{			//Node structure with which to build the stack
			Node * next;
			stackData data;
		};

		size_t _size;			//Holds number of nodes in the stack.
		Node * _top;			//Pointer to the top node in the stack.

};
template<typename stackData>
stack<stackData>::stack() {
	_size = 0;
	_top = NULL;
}
template<typename stackData>
stack<stackData>::~stack() {
}
template<typename stackData>
void stack<stackData>::push(stackData d) {
	Node * n = new Node;
	n -> data = d;
	n -> next = _top;
	_top = n;
	_size += 1;
}
template<typename stackData>
void stack<stackData>::pop() {
	if(!empty()) {
		Node * temp = _top;
		_top = _top -> next;
		temp -> next = NULL;
		delete temp;
		_size -= 1;
	}
}
template<typename stackData>
stackData stack<stackData>::top() const {
	return _top -> data;
}
template<typename stackData>
size_t stack<stackData>::size() const {
	return _size;
}
template<typename stackData>
bool stack<stackData>::empty() const {
	return _size == 0;
}
template<typename stackData>
void stack<stackData>::print() const {
	Node * n = _top;
	cout << "[";
	while(n != NULL) {
		cout << n -> data;
		if(!(n -> next == NULL)) {
			cout << ", ";
		}
		n = n -> next;
	}
	cout << "]";
}