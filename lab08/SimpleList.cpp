#include "SimpleList.h"
#include "EmptyListException.h"
#include "FullListException.h"
#include "InvalidIndexException.h"
#include <type_traits>
#include "tddFuncs.h"

using namespace std;

template<class T>
void destroy(T element) {
// do nothing
}

template <class T>
void destroy(T* element) {
// delete the pointer type
    delete element;
}

template <class T>
SimpleList<T>::SimpleList() {
    this->numElements=0;
    this->elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList() {

    for(int i = 0; i < numElements; i ++) {
        destroy(this->elements[i]);
    }
    
    delete[] this->elements;
    // this->elements = nullptr;
    numElements = 0;
}

template <class T>
T SimpleList<T>::at(int index) const {

    if(index < 0 || index >= numElements) {
        throw InvalidIndexException();
    }

    return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const {
    if(this->numElements == 0) {
        return true;
    }
    return false;
}

template <class T>
T SimpleList<T>::first() const {
    if(empty()) {
        throw EmptyListException();
    }
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const {
    if(empty()) {
        throw EmptyListException();
    }
    return elements[numElements-1];
}

template <class T> 
int SimpleList<T>::getNumElements() const {
    return this->numElements;
}

template <class T>
void SimpleList<T>::insert(T item) {
    if(numElements+1 > CAPACITY) {
        throw FullListException();
    }
    this->elements[numElements] = item;
    this-> numElements += 1;
}

template <class T>
void SimpleList<T>::remove(int index) {
    if(empty()) {
        throw EmptyListException();
    }
    if(index < 0 || index >= this->numElements) {
        throw InvalidIndexException();
    }
    if(std::is_pointer<T>::value){ destroy(this->elements[index]); }
    
    for(int i = index; i < numElements-1; i ++) {
        this->elements[i] = this->elements[i+1];
    }
    this->numElements -= 1;
}

