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
		}
		else {
			temp->next = root;
			root = temp;
		}
	}

	void addNodeToEndOfList(int data) {

		Node* temp = new Node(data);
		Node* iter = root;

		if (root == NULL) {
			root = temp;
		}
		else {

			while (iter->next != NULL) {
				iter = iter->next;
			}
			iter->next = temp;
		}
	}

	void addNodeByPosition(int data, int position) {
		Node* temp = new Node(data);
		Node* iter = root;
		int counter = 0;

		if (root == NULL) {
			root = temp;
		}
		else if (position == 0) {
			addNodeToTopOfList(data);
		}
		else  {
			while (iter->next != NULL) {
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
		}
		else if (root->data > data) {
			temp->next = root;
			root = temp;
		}
		else {
			Node* iter = root;
			while (iter->next != NULL && data > iter->next->data) {
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

		Node* iter = root;
		if (position == 0) {
			root = root->next;
			delete iter;
		}
		else {
			int counter = 0;
			while (iter->next != NULL) {
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

	void printList() {
		Node* iter = root;
		while (iter != NULL) {
			cout << iter->data << " ";
			iter = iter->next;
		}
		cout << endl;
	}

	int listLenght() {
		int elementCount = 0;
		Node* iter = root;
		while (iter != NULL) {
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
	list->addNodeByPosition(2, 2);
	list->addNodeToTopOfList(1);
	list->addNodeToEndOfList(999);
	list->printList();
	list->deleteNode(3);
	list->printList();
}
