//#include <iostream>

template <class T>
class node {
	public:
		T info;
		node<T> *next;
};


template <class T>
class nodePriority : public node<T>{
	public:
		//typedef NULL null;
		int priority;
		nodePriority(T info, int priority) {
			this->info = info;
			this->priority = priority;
			next = NULL;
		}

};

