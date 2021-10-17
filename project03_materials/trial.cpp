#include <iostream>
#include <new>
#include "stack.h"



void Stack::Resize(int n) {

	int* temp = NULL;

	try {

		temp = new int[2 * num];

	}
	catch (std::bad_alloc& bd) {

		throw StackFull();

		return;

	}



	for (int i = 0; i < num; i++) {

		temp[i] = array[i];

	}

	temp[num] = n;

	top = num;

	num = 2 * num;

	delete[] array;

	array = temp;

}

Stack::Stack(int n) {

	num = n;

	array = new int[n];

	top = -1;

}

Stack::~Stack(void) {

	delete[] array;

}

void Stack::Push(int n) {

	if (IsFull()) {

		Resize(n);

	}
	else {

		array[++top] = n;

	}

}

void Stack::Pop() {

	if (IsEmpty()) {

		throw StackEmpty();

	}
	else {

		top--;

	}

}

bool Stack::IsEmpty() const {

	if (top == -1) {

		return true;

	}
	else {

		return false;

	}

}

bool Stack::IsFull() const {

	if (top == num - 1) {

		return true;

	}
	else {

		return false;

	}

}

void Stack::MakeEmpty() {

	if (IsEmpty()) {

		return;

	}

	top = -1;

}

int Stack::Top() const {

	if (IsEmpty()) {

		throw StackEmpty();

	}
	else {

		return array[top];

	}

	return -1;

}

int Stack::Size() const {

	return top + 1;

}

int Stack::Max() const {

	int max = INT_MIN;

	if (IsEmpty()) {

		throw StackEmpty();

	}

	for (int i = 0; i <= top; i++) {

		if (array[i] > max) {

			max = array[i];

		}

	}

	return max;



}

int Stack::Min() const {

	int min = INT_MAX;

	if (IsEmpty()) {

		throw StackEmpty();

	}

	for (int i = 0; i <= top; i++) {

		if (array[i] < min) {

			min = array[i];

		}

	}

	return min;

}

int Stack::Peek(unsigned int n) const {

	if (top + 1 <= n) {

		throw StackInvalidPeek();

		return -1;

	}
	else {

		return array[top - n];

	}

}

int Stack::Capacity() const {

	return num;

}