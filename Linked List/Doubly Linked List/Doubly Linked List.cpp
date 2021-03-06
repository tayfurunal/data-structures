#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next, *prev;

	Node(int data,Node *next =NULL, Node *prev = NULL) {
		this->data = data;
		this->next = next;
		this->prev = prev;	
	}
};

class LinkedList {
private:
	Node *head, *tail;
	int elementCount = 0;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
	}

	void addNodeToTopOfList(int data)
	{
		Node* temp = new Node(data);
		
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
	}

	void addNodeToEndOfList(int data) {
		
		Node* temp = new Node(data);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
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
			while (iter->next != NULL) {
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
			head = temp;
			tail = temp;
		}
		else if (head->data > data) {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		else {
			Node* iter = head;
			while (iter->next != NULL && data > iter->next->data) {
				iter = iter->next;
			}
			temp->next = iter->next;
			iter->next = temp;
			temp->prev = iter;
			if (temp->next != NULL) {
				temp->next->prev = temp;
			}
		}
	}

	void deleteNode(int position) {
		if (head == NULL) {
			cout << "list is empty";
		}
		else if (position < 0 || position >= listLenght() ) {
			cout << "invalid value ";
		}else{
		Node* iter = head;
		if (position == 0) {
			head = head->next;
			if (head != NULL) {
				head->prev = NULL;
			}
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
			if (iter->next != NULL) {
				temp->next->prev = iter;
			}
			delete temp;
		}
		}
	}

	void printList() {
		Node* iter = head;
		while (iter != NULL) {
			cout << iter->data << " ";
			iter = iter->next;
		}
		cout << endl;
	}

	int listLenght() {
		int elementCount = 0;
		Node* iter = head;
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
	list->printList();
	list->deleteNode(5);
	list->printList();
}

