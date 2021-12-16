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
        T data; // äàííûå
        Node* next = nullptr; // óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
    };

    Node* head = nullptr; // óêàçàòåëü íà ïåðâûé ýëìåíò, ïî óìîë÷àíèþ nullptr
    int length = 0; // äëèíà ñïèñêà, ïî óìîë÷àíèþ 0

public:
    // ïóñòîé êîíñòðóêòîð, length = 0
    LinkedList() : length(0) {}
    // ïóñòîé êîíñòðóêòîð îïðåäåë¸ííîãî ðàçìåðà
    LinkedList(int length) : LinkedList() {
        if (length < 0) throw std::length_error(LL_NEGATIVE_SIZE_MESSAGE);
        // îáðàáîòêà èñêëþ÷åíèÿ

        Node** tmp = &(this->head);
        for (int i = 0; i < length; i++) {
            *tmp = new Node;
            (*tmp)->data = T();
            tmp = &((*tmp)->next);
        }
        this->length = length;
    }
    // Êîïèðîâàòü ýëåìåíòû èç ïåðåäàííîãî ìàññèâà
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
    // Êîïèðóþùèé êîíñòðóêòîð
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
    // äåñòðóêòîð
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

    //Ïîëó÷èòü ïåðâûé ýëåìåíò â ñïèñêå
    T getFirst() const {
        if (this->length == 0) throw std::length_error(LL_ZERO_SIZE_MESSAGE);

        return this->head->data;
    }
    // Ïîëó÷èòü ïîñëåäíèé ýëåìåíò â ñïèñêå
    T getLast() const {
        if (this->length == 0) throw std::length_error(LL_ZERO_SIZE_MESSAGE);

        Node* ptr = this->head;
        while (ptr->next != nullptr) ptr = ptr->next;
        return ptr->data;
    }
    // Ïîëó÷èòü ýëåìåíò ïî èíäåêñó
    T get(int index) const {
        if ((index < 0) || (index >= this->length)) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        Node* ptr;
        {
            int i = 0;
            for (i = 0, ptr = this->head; i < index; i++, ptr = ptr->next);
        }
        return ptr->data;
    }

    // Èçìåíèòü ýëåìåíò ïî èíäåêñó
    void set(const T& data, int index) {
        if (index < 0 || index >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);
        Node* ptr;
        {
            int i = 0;
            for (i = 0, ptr = this->head; i < index; i++, ptr = ptr->next);
        }
        ptr->data = data;
    }

    // Ïîëó÷èòü ñïèñîê èç âñåõ ýëåìåíòîâ, ñ startIndex ïî endIndex (âêëþ÷èòåëüíî)
    LinkedList<T>* getSublist(int start, int end) const { //end excluding
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

    // Ïîëó÷èòü äëèíó ñïèñêà
    int getLength() const { return this->length; }

    //Äîáàâëÿåò ýëåìåíò â êîíåö ñïèñêà
    void append(const T& data) {
        Node** ptr = &(this->head);
        while (*ptr != nullptr) ptr = &((*ptr)->next);

        (*ptr) = new Node;
        (*ptr)->data = data;

        this->length++;
    }

    // Äîáàâëÿåò ýëåìåíò â íà÷àëî ñïèñêà
    void prepend(const T& data) {

        Node* ptr = new Node{ data, this->head };
        this->head = ptr;

        this->length++;
    }

    /*bool find(const T& data) {
        Node* ptr = this->head;
        while (ptr != nullptr) {
            if (ptr->data == data) return true;
            ptr = ptr->next;
        }
        return false;
    }*/

    // óäàëåíèå ïî èíäåêñó
    void remove(int index) {
        if (index < 0 || index >= this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);

        // ýëåìåíò, ñëåäóþùèé äëÿ êîòîðîãî - íà÷àëî ñïèñêà
        Node preHead = { this->head->data, this->head };
        Node* ptr;

        // äîõîäèì äî íóæíîãî íàì (êàê ñëåäóþùåãî)
        {
            int i = 0;
            for (i = 0, ptr = &preHead; i < index; i++, ptr = ptr->next);
        }

        Node* tmp = ptr->next; // çàïîìèíàåì
        ptr->next = ptr->next->next; // ñäâèãàåì ñïèñîê
        delete tmp; // óäàëÿåì

        this->head = preHead.next; // â ñëó÷àå åñëè áûë óäàëåí ïåðâûé ýëåìåíò

        this->length--; // íå çàáûâàåì èçìåíèòü ðàçìåð ñïèñêà
    }

    // Âñòàâëÿåò ýëåìåíò â çàäàííóþ ïîçèöèþ
    void insert(const T& data, int index) {
        if (index < 0 || index > this->length) throw std::out_of_range(LL_INDEX_OUT_OF_RANGE_MESSAGE);

        // àíàëîãè÷íî remove, òîëüêî
        Node preHead = { this->head->data, this->head };
        Node* ptr;

        {
            int i = 0;
            for (i = 0, ptr = &preHead; i < index; i++, ptr = ptr->next);
        }

        ptr->next = new Node{ data, ptr->next }; //ñîçäàåì è âñòàâëÿåì íîâûé ýëåìåíò ñïèñêà
        this->head = preHead.next;

        this->length++; // óâåëè÷èâàåì äëèíó
    }

    //Ñöåïëÿåò äâà ñïèñêà
    LinkedList<T>* concat(const LinkedList<T>& list) const {
        Node* ptr1 = this->head;
        Node* ptr2 = list.head;

        LinkedList<T>* newList = new LinkedList<T>();
        Node** ptr = &(newList->head);
        // äîáàâëÿåì ïåðâûé ñïèñîê
        while (ptr1 != nullptr) {
            *ptr = new Node{ //ñîçäà¸ì ýëåìåíò
                    ptr1->data,
                    ptr1->next
            };
            // ïåðåõîäèì íà ñëåäóþùóþ èòåðàöèþ
            ptr1 = ptr1->next; // â ïåðâîì ñïèñêå
            ptr = &((*ptr)->next); // â ïîëó÷àåìîì ñïèñêå
        }
        // äîáàâëÿåì âòîðîé ñïèñîê (ptr = nullptr), àíàëîãè÷íî
        while (ptr2 != nullptr) {
            *ptr = new Node{
                    ptr2->data,
                    ptr2->next
            };

            ptr2 = ptr2->next;
            ptr = &((*ptr)->next);
        }

        newList->length = this->length + list.length; // íå çàáûâàåì óêàçûâàòü ðàçìåð
        return newList;
    }

    // ñðàâíåíèå ñïèñêîâ
    bool operator==(const LinkedList<T>& list) const {
        if (this->length != list.length) return false;

        for (int i = 0; i < this->length; i++) {
            if (this->get(i) != list.get(i)) return false;
        }

        return true;
    }

};


#endif // !LINKEDLIST_H