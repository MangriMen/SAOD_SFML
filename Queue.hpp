#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Queue {
public:
	Queue();
	~Queue();

	void push(T data);

	void pop();

	T front();

	T back();

	bool empty();

	template <typename T>
	class Node {
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	size_t Size;
	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
inline Queue<T>::Queue()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline Queue<T>::~Queue()
{
	while (!empty()) {
		pop();
	}
}

template<typename T>
inline void Queue<T>::push(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data, head);
		tail = head;
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data, nullptr);

		tail = current->pNext;
	}

	Size++;
}

template<typename T>
inline void Queue<T>::pop()
{
	Node<T>* temp = this->head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
inline T Queue<T>::front()
{
	return head->data;
}

template<typename T>
inline T Queue<T>::back()
{
	return tail->data;
}

template<typename T>
inline bool Queue<T>::empty()
{
	return Size ? false : true;
}