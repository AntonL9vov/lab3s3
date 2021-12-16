#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include "DynamicArray.h"

template<typename T>
class Queue {
private:
    DynamicArray<T> *data = nullptr;
public:
    Queue() {
        data = new DynamicArray<T>();
    }

    Queue(int size) {
        data = new DynamicArray<T>(size);
    }

    Queue(T *arr, int length) : Queue(length) {
        for (int i = 0; i < length; i++) {
            this->enqueue(arr[i]);
        }
    }

    Queue(const Queue<T> &other) {
        this->data = new DynamicArray<T>(*(other.data));
    }

    int getLength() {
        return this->data->getLength();
    }

    void enqueue(T item) {
        this->data->prepend(item);
    }

    T dequeue() {
        try {
            T tmp = this->data->get(this->data->getLength() - 1);
            this->data->removeLast();
            return tmp;
        }
        catch (const std::exception &e) {
            throw e;
        }
    }

};

#endif // !QUEUE_H