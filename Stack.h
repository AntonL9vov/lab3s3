#pragma once
#ifndef STACK_H
#define STACK_H
#include "List.h"

template <typename T>
class Stack {
private:
    LinkedList<T>* data;
public:
    Stack() {
        this->data = new LinkedList<T>();
    }
    void push(T item) {
        this->data->prepend(item);
    }
    int getLength() { return this->data->getLength(); }
    Stack(T* arr, int length) : Stack() {
        for (int i = 0; i < length; i++) {
            this->push(arr[i]);
        }
    }
    Stack(const Stack<T>& other) { this->data = new LinkedList<T>(*(other.data)); }
    T pop() {
        T tmp = this->data->getFirst();
        this->data->remove(0);
        return tmp;
    }
};



#endif // !STACK_H