#include <iostream>
#include "./node.hpp"

using namespace std;

template <class T>

class Stack {
    public:
        typedef node<T> Node;
        Node* top;
        int size;

        Stack() {
            top = NULL;
            size = 0;
        }

        bool isEmpty() {
            return top == NULL;
        }

        void push(T info) {
            Node* node = new Node;
            node->info = info;
            node->next = top;
            top = node;
            size++;
        }

        void pop() {
            if (!isEmpty()) {
                Node* temp = top;
                top = top->next;
                delete temp;
                size--;
            }
        }
       

        ~Stack() {
            while (top != NULL) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        }
};


