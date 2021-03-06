#include "pch.h"
#include <iostream>
using namespace std;

#define STACK_SIZE 5
class Node {
public:
	int top = -1;
	int data[STACK_SIZE];
};

class Stack {
public:
	Node* stack = new Node();

	bool isFull() {
		if (stack->top == STACK_SIZE - 1)
			return true;
		return false;
	}

	bool isEmpty() {
		if (stack->top == -1)
			return true;
		return false;
	}

	void push(int data) {
		if (!isFull()) {
			stack->top++;
			stack->data[stack->top] = data;
		}
	}

	void pop() {
		if (!isEmpty())
		{
			stack->data[stack->top] = NULL;
			stack->top--;
		}
	}

	void printStack(){
		while (true) {
			if (isEmpty())
				break;
			cout << stack->data[stack->top]<<endl;
			stack->top--;
		}
	}
};

int main()
{
	Stack* stackArray = new Stack();

	stackArray->push(10);
	stackArray->push(20);
	stackArray->push(30);
	stackArray->push(40);
	stackArray->push(50);
	stackArray->printStack();
}
