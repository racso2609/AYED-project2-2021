#ifndef __node__hpp__
#define __node__hpp__
#endif

template <class T>
class node {
	public:
		T info;
		node<T> *next;
};


template <class T>
class nodePriority : public node<T>{
	public:
		int priority;
		nodePriority<T> *next;
		nodePriority(T info, int priority) {
			this->info = info;
			this->priority = priority;
			next = NULL;

		}

};

