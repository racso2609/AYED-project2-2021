#include <iostream>
#ifndef __node__hpp__
#include "./node.hpp"
#endif

using namespace std;

template <class T>
class list {
 	node<T> *pFirst;
	node<T> *pLast;
 	int n;
  	public:
	  	typedef node<T> *pos;
    	list();
		~list();
		bool isEmpty();
		pos first();
		pos last();
		void next(pos &pValue);
		T* get(pos pValue);
    	void insert(T x, pos pValue);
		void del(pos pValue);
		int size();
};

template <class T>
list<T>::list(){
    n = 0; 
    pFirst = new node<T>();
	pLast = pFirst;
	(*pFirst).next = NULL;
}

template <class T>
list<T>::~list(){
    node<T> *pTemp;
    while(pFirst != NULL){
        pTemp = pFirst;
        pFirst = (*pFirst).next;
        delete pTemp;
    }
}

template <class T>
bool list<T>::isEmpty(){
    return (*pFirst).next == NULL;
}

template <class T>
typename list<T>::pos list<T>::first(){
	return pFirst;
}

template <class T>
typename list<T>::pos list<T>::last(){
	return pLast;
}

template <class T>
void list<T>::next(pos &pValue){
	if (pValue != NULL)
		pValue = (*pValue).next;
}

template <class T>
T* list<T>::get(pos pValue){
	if (pValue != NULL)
		return &((*((*pValue).next)).info);
	return NULL;
}

template <class T>
void list<T>::insert(T x, pos pValue){
	node<T> *pNew = new node<T>();
	(*pNew).info = x;
	if (pFirst == pValue){ // primero
		(*pNew).next = (*pFirst).next;
		(*pFirst).next = pNew;
	}else{
		(*pNew).next = (*pValue).next;
		(*pValue).next = pNew;
	}
	if(pLast == pValue)
		pLast = pNew;
	n++;
}

template <class T>
void list<T>::del(pos pValue){
	if ((*pValue).next == pLast)
		pLast = pValue;
	node<T> *pTemp = (*pValue).next;
	(*pValue).next = (*((*pValue).next)).next;
	delete pTemp;
	n--;
}

template <class T>
int list<T>::size(){
    return n;
}
