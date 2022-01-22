#pragma once
#include<iostream>
template<typename T>
class Stack {
	T* arr;
	size_t size;
	size_t capacity;
public:
	Stack(size_t cap);
	~Stack() { delete[] arr; }
	void push(const T& number);
	void print();
	void pop();
	bool isEmpty();
};

template <typename T>
Stack<T>::Stack(size_t cap)
{
	arr = new int[cap];
	size = 0;
	capacity = cap;
}

template <typename T>
void Stack<T>::push(const T& number) {
	if (size == capacity)
	{
		capacity *= 2;
		int* myArr = new T[capacity];

		for (int i = 0; i < capacity - 1; i++)
		{
			myArr[i] = arr[i];
		}

		delete[] arr;
		arr = myArr;
	}

	arr[size] = number;
	++size;
}

template <typename T>
void Stack<T>::pop() {
	if (!size) return;
	else {
		--size;
	}
}

template <typename T>
bool Stack<T>::isEmpty() {
	return size;
}

template <typename T>
void Stack<T>::print() {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}