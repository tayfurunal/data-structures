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

class LinkedList {
public:
	Node* root = NULL;

	void addNodeToTopOfList(int data)
	{
		Node* temp = new Node(data);

		if (root == NULL) {
			root = temp;
			temp->next = root;
		}
		else {
			temp->next = root;
			Node* iter = root;
			while (iter->next != root) {
				iter = iter->next;
			}
			iter->next = temp;
			root = temp;
		}
	}

	void addNodeToEndOfList(int data) {

		Node* temp = new Node(data);
		Node* iter = root;

		if (root == NULL) {
			root = temp;
			temp->next = root;
		}
		else {

			while (iter->next != root) {
				iter = iter->next;
			}
			temp->next = iter->next;
			iter->next = temp;
		}
	}

	void addNodeByPosition(int data, int position) {
		Node* temp = new Node(data);
		Node* iter = root;
		int counter = 0;

		if (root == NULL) {
			root = temp;
			temp->next = root;
		}
		else if (position == 0) {
			addNodeToTopOfList(data);
		}
		else {
			while (iter->next != root) {
				if (position - 1 == counter) {
					break;
				}
				iter = iter->next;
				counter++;
			}
			temp->next = iter->next;
			iter->next = temp;
		}
	}

	void addNodeOrdered(int data) {
		Node* temp = new Node(data);

		if (root == NULL) {
			root = temp;
			temp->next = root;
		}
		else if (root->data > data) {
			temp->next = root;
			Node* iter = root;
			while (iter->next != root) {
				iter = iter->next;
			}
			iter->next = temp;
			root = temp;
		}
		else {
			Node* iter = root;
			while (iter->next != root && data > iter->next->data) {
				iter = iter->next;
			}
			temp->next = iter->next;
			iter->next = temp;
		}
	}

	void deleteNode(int position) {
		if (root == NULL) {
			cout << "list is empty";
		}
		else if (position < 0 || position >= listLenght()) {
			cout << "invalid value ";
		}
		else {
			Node* iter = root;
			if (position == 0) {
				Node* temp = iter;
				while (temp->next != root) {
					temp = temp->next;
				}
				root = root->next;
				temp->next = root;
				delete iter;
			}
			else {
				int counter = 0;
				while (iter->next != root) {
					if (counter == (position - 1)) {
						break;
					}
					iter = iter->next;
					counter++;
				}
				Node* temp = iter->next;
				iter->next = temp->next;
				delete temp;
			}
		}
	}

	void printList() {
		Node* iter = root;
		cout << iter->data << " ";
		iter = iter->next;
		while (iter != root) {
			cout << iter->data << " ";
			iter = iter->next;
		}
		cout << endl;
	}

	int listLenght() {
		int elementCount = 1;
		Node* iter = root;
		while (iter->next != root) {
			iter = iter->next;
			elementCount++;
		}
		return elementCount;

	}
};

int main()
{
	LinkedList* list = new LinkedList();
	list->addNodeOrdered(400);
	list->addNodeOrdered(40);
	list->addNodeOrdered(4);
	list->addNodeOrdered(450);
	list->addNodeOrdered(50);
	list->printList();
	list->addNodeByPosition(999, 2);
	list->printList();
	list->addNodeByPosition(999, 0);
	list->printList();
}
