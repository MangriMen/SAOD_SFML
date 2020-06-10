#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

template <typename T>
class Stack {
public:
	Stack();
	~Stack();

	void push(T data);

	void pop();

	T top();

	vector<T> out();

	T checkSum();

	int runNumber();

	size_t size();

	void empty();

private:
	template <typename T>
	class Node
	{
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
};

template<typename T>
Stack<T>::Stack()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	empty();
}

template<typename T>
void Stack<T>::push(T data)
{
	head = new Node<T>(data, head);

	Size++;
}

template<typename T>
void Stack<T>::pop()
{
	Node<T>* temp = this->head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
inline T Stack<T>::top()
{
	return head->data;
}

template<typename T>
inline vector<T> Stack<T>::out()
{
	int counter = 0;
	vector<T> numbers;

	Node<T>* current = this->head;

	while (current != nullptr) {
		numbers.push_back(current->data);
		current = current->pNext;
		counter++;
	}

	return numbers;
}

template<typename T>
inline T Stack<T>::checkSum()
{
	int counter = 0;
	int sum = 0;

	Node<T>* current = this->head;

	while (current != nullptr) {
		sum += current->data;
		current = current->pNext;
		counter++;
	}
	return sum;
}

template<typename T>
inline int Stack<T>::runNumber()
{
	int t = 0, c = 0;

	int counter = 0;

	Node<T>* current = this->head;

	while (current->pNext != nullptr) {
		if (current->data <= current->pNext->data) {
			t++;
		}
		else {
			c++;
		}
		current = current->pNext;
		counter++;
	}
	c++;
	return c;
}

template<typename T>
inline size_t Stack<T>::size()
{
	return Size;
}

template<typename T>
void Stack<T>::empty()
{
	while (Size) {
		pop();
	}
}
