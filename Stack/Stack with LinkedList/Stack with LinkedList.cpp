#include "pch.h"
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data, Node* next = NULL) {
		this->data = data;
		this->next = next;
	}
};

class Stack {
public:
	Node* top = NULL, *temp;

	void push(int data) {
		Node* NodeINStack = new Node(data);
		if (top == NULL) {
			top = NodeINStack;
		}
		else {
			NodeINStack->next = top;
			top = NodeINStack;
		}
	}
	
	void pop() {
		if (top == NULL) {
			cout << "Stack is empty";
		}
		else {
			temp = top->next;
			delete top;
			top = temp;
		}
	}

	void printList() {
		Node* iter = top;
		while (iter != NULL) {
			cout << iter->data << " ";
			iter = iter->next;
		}
		cout << endl;
	}
};

int main()
{
	Stack* stackList = new Stack();

	stackList->push(10);
	stackList->push(20);
	stackList->push(30);
	stackList->push(40);
	stackList->pop();
	stackList->printList();

}
