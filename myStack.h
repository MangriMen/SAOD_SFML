#include <cstdio>
#ifndef Stack_H
#define Stack_H
 
template<typename T>
class Stack {
public:
    Stack();
    ~Stack();
 
 	bool empty();
    size_t size();
    void push(int);
    T front();
    void pop();
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
Stack<T>::Stack() {
	size_ = 0;
	head_ = nullptr;
}
 

template<typename T>
Stack<T>::~Stack() {
    while (size_) {
        pop();
    }  
}
 
template <typename T>
void Stack<T>::push(int data) {
    if (head_ == nullptr) {
        head_ = new Node<T>(data);
    } else {
        Node<T>* new_element = new Node<T>(data);
        new_element->next_ = head_;
        head_ = new_element;
    }
    ++size_;
}

template <typename T>
bool Stack<T>::empty() {
	return size_ == 0;
}

template <typename T>
size_t Stack<T>::size() {
	return size_;
}

template <typename T>
void Stack<T>::pop() {
	if (head_ != nullptr) {
		Node<T>* t = head_->next_;
		delete head_;
		head_ = t;
		--size_;
	}
}


template <typename T>
T Stack<T>::front() {
	return head_->data_;
}
 
#endif // Stack_H
