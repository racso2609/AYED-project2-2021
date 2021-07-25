#include <iostream>
#ifndef __node__hpp__
#include "./node.hpp"
#endif

#ifndef __stack__hpp__
#define __stack__hpp__
#endif

using namespace std;

template <class T>

class Stack {
    private:
        typedef node<T> Node;
    public:
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


