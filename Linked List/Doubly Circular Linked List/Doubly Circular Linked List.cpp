#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next, *prev;

	Node(int data, Node *next = NULL, Node *prev = NULL) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class LinkedList {
private:
	Node *head, *tail;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addNodeToTopOfList(int data)
	{
		Node* temp = new Node(data);
		Node* iter;

		if (head == NULL) {
			head = temp;
			head->next = head;
			head->prev = head;
		}
		else {
			head->prev->next = temp;
			temp->next = head;
			temp->prev = head->prev;
			head->prev = temp;
			head = temp;
		}
	}

	void addNodeToEndOfList(int data)
	{
		Node* temp = new Node(data);
		Node* iter;

		if (head == NULL) {
			head = temp;
			head->next = head;
			head->prev = head;
		}
		else {
			head->prev->next = temp;
			temp->next = head;
			temp->prev = head->prev;
			head->prev = temp;
		}
	}

	void addNodeByPosition(int data, int position) {
		Node* temp = new Node(data);
		Node* iter = head;
		int counter = 0;

		if (position == 0) {
			addNodeToTopOfList(data);
		}
		else {
			while (iter->next != head) {
				if (counter == (position - 1)) {
					break;
				}
				iter = iter->next;
				counter++;
			}
			temp->next = iter->next;
			iter->next->prev = temp;
			temp->prev = iter;
			iter->next = temp;
		}
	}

	void addNodeOrdered(int data) {
		Node* temp = new Node(data);

		if (head == NULL) {
			addNodeToTopOfList(data);
		}
		else if (head->data > data) {
			temp->next = head;
			head->prev->next = temp;
			temp->prev = head->prev;
			head->prev = temp;
			head = temp;
		}
		else {
			Node* iter = head;
			while (iter->next != head && data > iter->next->data) {
				iter = iter->next;
			}
			temp->next = iter->next;
			iter->next = temp;
			temp->prev = iter;
			temp->next->prev = temp;
		}
	}

	void deleteNode(int position) {
		if (head == NULL) {
			cout << "list is empty";
		}
		else if (position < 0 || position >= listLenght()) {
			cout << "invalid value ";
		}
		else {
			Node* iter = head;
			if (position == 0) {
				head = head->next;
				head->prev = iter->prev;
				head->prev->next = head;
				delete iter;
			}
			else {
				int counter = 0;
				while (iter->next != head) {
					if (counter == (position - 1)) {
						break;
					}
					iter = iter->next;
					counter++;
				}
				Node* temp = iter->next;
				iter->next = temp->next;
				temp->next->prev = iter;
				delete temp;
			}
		}
	}

	void printList() {
		Node* iter = head;
		cout << iter->data << " ";
		iter = iter->next;
		while (iter!= head) {
			cout << iter->data << " ";
			iter = iter->next;
		}
		cout << endl;
	}

	int listLenght() {
		int elementCount = 0;
		Node* iter = head;
		while (iter->next != head) {
			iter = iter->next;
			elementCount++;
		}
		return elementCount;

	}

};

int main()
{
	LinkedList* list = new LinkedList();
	list->addNodeOrdered(10);
	list->addNodeOrdered(20);
	list->printList();
	list->deleteNode(0);
	list->printList();
}
