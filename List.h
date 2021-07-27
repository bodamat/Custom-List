//
// Created by bomtv on 27.07.2021.
//

#ifndef LISTTASK_LIST_H
#define LISTTASK_LIST_H

#include "iostream"

template <typename T>
class List{
private:
	struct Node {
		T data;
		Node* next;
		Node* prev;
	};
	
	unsigned length = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	List();
	~List();
	void addHead(const T& data);
	void addTail(const T& data);
	void removeHead();
	void removeTail();
	bool isEmpty();
	void clear();
	void printHead() const;
	void printTail() const;
	unsigned size();
};

/**
 * Implementation List
 * @tparam T
 */

template <typename T>
List <T>::List(): length(0), head(nullptr), tail(nullptr) {}

template <typename T>
List <T>::~List(){
	clear();
}

template <typename T>
void List <T>::addHead(const T &data){
	Node* t = new Node();
	t->next = nullptr;
	t->prev = nullptr;
	t->data = data;
	
	if (head != nullptr) {
		Node* t2 = head;
		t2->next = t;
		t->prev = t2;
	} else {
		tail = t;
	}
	
	head = t;
	length++;
}

template <typename T>
void List <T>::addTail(const T &data){
	Node* t = new Node();
	t->next = nullptr;
	t->prev = nullptr;
	t->data = data;
	
	if (tail != nullptr) {
		Node* t2 = tail;
		t2->prev = t;
		t->next = t2;
	} else {
		head = t;
	}
	
	tail = t;
	length++;
}

template <typename T>
void List <T>::removeHead(){
	if (head == nullptr) throw std::invalid_argument("List is empty!");
	
	Node* t = head;
	head = t->prev;
	
	if (t->prev != nullptr) {
		Node* t2 = t->prev;
		t2->next = nullptr;
	} else {
		tail = nullptr;
	}
	
	delete t;
	length--;
}

template <typename T>
void List <T>::removeTail(){
	if (tail == nullptr) throw std::invalid_argument("List is empty!");
	
	Node* t = tail;
	tail = t->next;
	
	if (t->next != nullptr) {
		Node* t2 = t->next;
		t2->prev = nullptr;
	} else {
		head = nullptr;
	}
	
	delete t;
	length--;
}

template <typename T>
bool List <T>::isEmpty(){
	return length == 0;
}

template <typename T>
void List <T>::clear(){
	while (tail != nullptr)
		removeTail();
}

template <typename T>
void List <T>::printHead() const{
	if (head == nullptr) throw std::invalid_argument("List is empty!");
	
	Node* t = head;
	T data = t->data;
	
	std::cout << "Data from head: " << data << std::endl;
}

template <typename T>
void List <T>::printTail() const{
	if (tail == nullptr) throw std::invalid_argument("List is empty!");
	
	Node* t = tail;
	T data = t->data;
	
	std::cout << "Data from tail: " << data << std::endl;
}

template <typename T>
unsigned List <T>::size(){
	return length;
}


#endif //LISTTASK_LIST_H
