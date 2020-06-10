#include <cstdio>
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
 
template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
 
 	bool empty();
    size_t size();
    void push(int);
    T front();
    void pop();
    void print();
private:
	template <typename R>
    class Node {
    public:
        Node* next_;
        R data_;
        
        Node(T data = R(), Node* next = nullptr){
            data_ = data;
            next_ = next;
        }
    };
    size_t size_;
    Node<T>* head_;
};
 
template<typename T>
Queue<T>::Queue() {
	size_ = 0;
	head_ = nullptr;
}
 

template<typename T>
Queue<T>::~Queue() {
    while (size_) {
        pop();
    }  
}
 
template <typename T>
void Queue<T>::push(int data) {
    if (head_ == nullptr) {
        head_ = new Node<T>(data);
    } else {
        Node<T>* current = head_;
        while (current->next_ != nullptr) {
            current = current->next_;
        }
        current->next_ = new Node<T>(data);
    }
    ++size_;
}

template <typename T>
bool Queue<T>::empty() {
	return size_ == 0;
}

template <typename T>
size_t Queue<T>::size() {
	return size_;
}

template <typename T>
void Queue<T>::pop() {
	if (head_ != nullptr) {
		Node<T>* t = head_->next_;
		delete head_;
		head_ = t;
		--size_;
	}
}


template <typename T>
T Queue<T>::front() {
	return head_->data_;
}


template <typename T>
void Queue<T>::print() {
	Node<T>* t = head_;
	while (t != nullptr) {
		std::cout << t->data_ << " ";
		t = t->next;
	}
	std::cout << "\n";
}

 
#endif // QUEUE_H
