#include <iostream>
#include <string>
#ifndef __node__hpp__
#include "./node.hpp"
#endif
using namespace std;

template <class T>

class PriorityQueue {
private:
  nodePriority<T> *first;
  nodePriority<T> *last;
  int size;
  typedef nodePriority<T> Node;

public:
  PriorityQueue() {
    first = NULL;
    last = NULL;
    size = 0;
  }

  bool isEmpty() { return size == 0; }

  void enqueue(T info, int priority) {
    Node *nodes = new Node(info, priority);

    if (isEmpty())
      first = last = nodes;
    else {
      Node *temp = first;

      while (temp->next != NULL && temp->next->priority >= priority)
        temp = temp->next;

      if (temp->next == NULL) {
        // cout<<temp->priority<< priority<<endl;
        if (temp->priority < priority) {
          nodes->next = temp;
          first = nodes;
        } else {
          temp->next = nodes;
          last = nodes;
        }
      } else {
        if (temp->priority < priority) {
          nodes->next = temp;
          first = nodes;
        } else {
          nodes->next = temp->next;
          temp->next = nodes;
        }
      }
    }
    size++;
  }

  void dequeue() {
    if (!isEmpty()) {
      Node *temp = first;
      first = first->next;
      delete temp;
      size--;
      if (first == NULL)
        last = NULL;
    }
  }

  int sizes() { return size; }

  Node *head() { return first; }

  ~PriorityQueue() {
    while (first != NULL) {
      Node *temp = first;
      first = first->next;
      delete temp;
    }
  }
};
