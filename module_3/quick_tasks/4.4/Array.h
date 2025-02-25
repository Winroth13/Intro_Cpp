#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <stdexcept>

template <typename T>
class Array {
private:
	int size;
	T* elements;
public:
	Array(const int size);
	Array(const Array<T>& other);
	Array& operator=(const Array<T>& other);
	~Array();

	T& operator[](const int index);
	const T& operator[](const int index) const;

	T& GetElem(const int index);
	int GetSize() const;
};

template <typename T>
Array<T>::Array(const int size)
	: size(size) {
	this->elements = new T[this->size];
}

template <typename T>
Array<T>::Array(const Array<T>& other)
	: size(other.size) {
	elements = new T[this->size];

	for (int i = 0; i < this->size; ++i) {
		this->elements[i] = other.elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		this->size = other.size;

		delete[] elements;

		this->elemensts = new T[size];

		for (int i = 0; i < this->size; ++i) {
			this->elements[i] = other.elements;
		}
	}

	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](const int index) {
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](const int index) const {
	return elements[index];
}

template <typename T>
T& Array<T>::GetElem(const int index) {
	if (index >= this->size) {
		throw std::out_of_range("Max index of " + std::to_string(this->size) + ".");
	}
	else {
		return this->elements[index];
	}
}

template <typename T>
int Array<T>::GetSize() const {
	return this->size;
}

#endif