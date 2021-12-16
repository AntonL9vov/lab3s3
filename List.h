#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <string>

const std::string LL_INDEX_OUT_OF_RANGE_MESSAGE = "(LL) Quack! Index out of range.";
const std::string LL_NEGATIVE_SIZE_MESSAGE = "(LL) Quack! Size < 0.";
const std::string LL_ZERO_SIZE_MESSAGE = "(LL) Quack! Size = 0.";

template <typename T> class LinkedList {
private:

    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    int length = 0;

public:

    LinkedList() : length(0) {}

    LinkedList(int length) : LinkedList() {
        if (length < 0) throw std::length_error(LL_NEGATIVE_SIZE_MESSAGE);

        Node** tmp = &(this->head);
        for (int i = 0; i < length; i++) {
            *tmp = new Node;
            (*tmp)->data = T();
            tmp = &((*tmp)->next);
        }
        this->length = length;
    }
    LinkedList(T* datas, int length) : LinkedList() {
        if (length < 0) throw std::length_error(LL_NEGATIVE_SIZE_MESSAGE);

        Node** ptr = &(this->head);
        for (int i = 0; i < length; i++) {
            *ptr = new Node;
            (*ptr)->data = datas[i];
            ptr = &((*ptr)->next);
        }

        this->length = length;
    }
    LinkedList(const LinkedList<T>& list) {
        Node* ptr = list.head;
        Node** newPtr = &(this->head);

        for (int i = 0; i < list.length; i++, ptr = ptr->next) {
            *newPtr = new Node;
            (*newPtr)->data = ptr->data;
            newPtr = &((*newPtr)->next);

        }

        this->length = list.length;
    }
    virtual ~LinkedList() {
        Node* ptr = this->head;
        Node* next;
        while (ptr != nullptr) {
            next = ptr->next;
            delete ptr;
            ptr = next;
        }
        this->length = 0;
    }

    T getFirst() const {
        if (this->length == 0) throw std::length_error(LL_ZERO_SIZE_MESSAGE);

        return this->head->data;
    }
    T getLast() const {
        if (this->length == 0) throw std::length_error(LL_ZERO_SIZE_MESSAGE);

        Node* ptr = this->head;
        while (ptr->next != nullptr) ptr = ptr->next;
        return ptr->data;
    }

    T get(int index) const {
        if ((index < 0) || (index >= this->length)) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        Node* ptr;
        {
            int i = 0;
            for (i = 0, ptr = this->head; i < index; i++, ptr = ptr->next);
        }
        return ptr->data;
    }

    void set(const T& data, int index) {
        if (index < 0 || index >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        Node* ptr;
        {
            int i = 0;
            for (i = 0, ptr = this->head; i < index; i++, ptr = ptr->next);
        }
        ptr->data = data;
    }

    LinkedList<T>* getSublist(int start, int end) const {
        if (start < 0 || start >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        if (end < 0 || end >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        if (start > end) throw std::logic_error("Quack! End must be not less than start.");

        LinkedList<T>* newList = new LinkedList<T>();

        Node* ptr = this->head;
        Node** newPtr = &newList->head;

        for (int i = 0; i <= end; i++, ptr = ptr->next) {
            if (i >= start) {
                *newPtr = new Node;
                (*newPtr)->data = ptr->data;
                newPtr = &((*newPtr)->next);
            }

        }

        newList->length = end - start + 1;

        return newList;
    }

    int getLength() const { return this->length; }

    void append(const T& data) {
        Node** ptr = &(this->head);
        while (*ptr != nullptr) ptr = &((*ptr)->next);

        (*ptr) = new Node;
        (*ptr)->data = data;

        this->length++;
    }

    void prepend(const T& data) {

        Node* ptr = new Node{ data, this->head };
        this->head = ptr;

        this->length++;
    }


    void remove(int index) {
        if (index < 0 || index >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);

        Node preHead = { this->head->data, this->head };
        Node* ptr;

        {
            int i = 0;
            for (i = 0, ptr = &preHead; i < index; i++, ptr = ptr->next);
        }

        Node* tmp = ptr->next;
        ptr->next = ptr->next->next;
        delete tmp;

        this->head = preHead.next;

        this->length--;
    }

    void insert(const T& data, int index) {
        if (index < 0 || index > this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);

        Node preHead = { this->head->data, this->head };
        Node* ptr;

        {
            int i = 0;
            for (i = 0, ptr = &preHead; i < index; i++, ptr = ptr->next);
        }

        ptr->next = new Node{ data, ptr->next };
        this->head = preHead.next;

        this->length++;
    }

    LinkedList<T>* concat(const LinkedList<T>& list) const {
        Node* ptr1 = this->head;
        Node* ptr2 = list.head;

        LinkedList<T>* newList = new LinkedList<T>();
        Node** ptr = &(newList->head);
        while (ptr1 != nullptr) {
            *ptr = new Node{
                    ptr1->data,
                    ptr1->next
            };
            ptr1 = ptr1->next;
            ptr = &((*ptr)->next);
        }
        while (ptr2 != nullptr) {
            *ptr = new Node{
                    ptr2->data,
                    ptr2->next
            };

            ptr2 = ptr2->next;
            ptr = &((*ptr)->next);
        }

        newList->length = this->length + list.length;
        return newList;
    }

    bool operator==(const LinkedList<T>& list) const {
        if (this->length != list.length) return false;

        for (int i = 0; i < this->length; i++) {
            if (this->get(i) != list.get(i)) return false;
        }

        return true;
    }

};


#endif // !LINKEDLIST_H