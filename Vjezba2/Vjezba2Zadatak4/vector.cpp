#include "vector.h"

void MyVector::vector_new(size_t sz)
{
	arr = new int[sz];
	size = 0;
	capacity = 1;
}
void MyVector::vector_delete()
{
	delete[] arr;
}
void MyVector::vector_push_back(int n)
{

	if (size == capacity)
	{
		capacity *= 2;
		int* myArr = new int[capacity];
		for (int i = 0; i < capacity - 1; i++)
		{
			myArr[i] = arr[i];
		}

		delete[] arr;

		arr = myArr;
	}

	arr[size] = n;
	size++;
}
void MyVector::vector_pop_back()
{
	size--;
}
int& MyVector::vector_front()
{
	return arr[0];
}
int& MyVector::vector_back()
{
	return arr[size - 1];
}
size_t MyVector::vector_size()
{
	return size;
}
void MyVector::print_vector()
{
	for (size_t i = 0; i < vector_size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
