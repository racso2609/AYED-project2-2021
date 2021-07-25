#include <iostream>
#include <string>
#include "./node.hpp"
using namespace std;


template <class T>

class PriorityQueue {
private:
	nodePriority<T>* first;
	nodePriority<T>* last;
	int size;
public:
	typedef nodePriority<T> Node;
	PriorityQueue() {
		first = NULL;
		last = NULL;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	void enqueue(T info, int priority) {
		Node* node = new Node(info, priority);

		if (isEmpty())
			first = last = node;
		else {
			Node* temp = first;

			while (temp->next != NULL && temp->next->priority <= priority)
				temp = temp->next;

			if (temp->next == NULL) {
				if (temp->priority > priority) {
					node->next = temp;
					first = node;
				} else {
					temp->next = node;
					last = node;
				}
			} else {
				if (temp->priority > priority) {
					node->next = temp;
					first = node;
				} else {
					node->next = temp->next;
					temp->next = node;
				}
			}
		}
		size++;
	}
	
	void dequeue() {
		if (!isEmpty()) {
			Node* temp = first;
			first = first->next;
			delete temp;
			size--;
			if (first == NULL)
				last = NULL;
		}
	}

	int sizes() {
		return size;
	}

	Node* head() {
		return first;
	}

	~PriorityQueue() {
		while (first != NULL) {
			Node* temp = first;
			first = first->next;
			delete temp;
		}
	}
};


