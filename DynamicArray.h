#ifndef ARRAY_H
#define ARRAY_H
// #include "sequence.h"

#include <stdexcept>
#include <string>
#include <functional>

const std::string DA_INDEX_OUT_OF_RANGE_MESSAGE = "(DA) Quack! Index out of range.";
const std::string DA_NEGATIVE_SIZE_MESSAGE = "(DA) Quack! Size < 0.";
const std::string DA_ZERO_SIZE_MESSAGE = "(DA) Quack! Size = 0.";


template <typename T>
class DynamicArray
{
private:

    T* data;
    int size = 0;
    int length = 0;

public:
    DynamicArray() : size(0), length(0) {}

    DynamicArray(int size) : size(size) {
        if (size < 0) throw std::length_error(DA_NEGATIVE_SIZE_MESSAGE);
        this->data = new T[size];
        this->length = 0;
    }

    DynamicArray(T* data, int size) : DynamicArray(size) {
        for (int i = 0; i < size; i++)
            this->data[i] = data[i];
        this->length = size;
    }

    DynamicArray(const DynamicArray<T>& array, int length) : DynamicArray(length) {
        if (length > array.length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        for (int i = 0; i < length; i++)
            this->data[i] = array.data[i];

        this->length = length;
    }

    DynamicArray(const DynamicArray<T>& array) :
            DynamicArray(array.data, array.length) {}

    virtual ~DynamicArray() {
        delete[] this->data;
        this->size = 0;
        this->length = 0;
    }

    T get(int index) const {
        if (index < 0 || index >= this->length)
            throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        return this->data[index];
    }

    T getFirst(){
        return this->get(0);
    }

    T getLast(){
        return this->get(length - 1);
    }


    int getSize() const { return this->size; }

    int getLength() const { return this->length; }

    void set(const T& value, int index) {
        if (index < 0 || index >= this->size) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        if (this->length < index + 1) {
            this->length += index + 1;
        }

        *(this->data + index) = value;
    }

    bool isEmpty()
    {
        bool a = (this->length == 0);
        return a;
    }


    void resize(int size) {
        if (size < 0) throw std::length_error(DA_NEGATIVE_SIZE_MESSAGE);

        T* newData = new T[size];

        for (int i = 0; i < (this->size > size ? size : this->size); i++)
            newData[i] = data[i];

        this->data = newData;

        this->size = size;
    }

    void append(T elem) {
        int o_size = this->size;
        int o_length = this->length;

        if (o_length < o_size) {
            this->data[o_length] = elem;
            this->length++;
        }
        else {
            if (size == 0) {
                this->resize(20);
            }
            else {
                this->resize(o_size * 2);
            }
            this->data[o_length] = elem;
            this->length++;
        }
    }

    void prepend(T elem) {
        int o_size = this->size;
        int o_length = this->length;
        if (o_length < o_size) {
            T tmp1 = elem;
            T tmp2;
            for (int i = 0; i < o_length; i++) {
                tmp2 = this->data[i];
                this->data[i] = tmp1;
                tmp1 = tmp2;
            }
            this->data[o_length] = tmp1;
            this->length++;
        }
        else {
            if (size == 0) {
                this->resize(20);
            }
            else {
                this->resize(o_size * 2);
            }
            T tmp1 = elem;
            T tmp2;
            for (int i = 0; i < o_length; i++) {
                tmp2 = this->data[i];
                this->data[i] = tmp1;
                tmp1 = tmp2;
            }
            this->data[o_length] = tmp1;
            this->length++;
        }
    }


    bool operator==(const DynamicArray<T>& arr) const {
        if (this->length != arr.length) return false;

        for (int i = 0; i < this->length; i++)
            if (this->get(i) != arr.get(i)) return false;


        return true;
    }

    DynamicArray<T>& operator=(const DynamicArray& arr) {
        delete[] this->data;


        this->size = arr.size;
        this->length = arr.length;
        this->data = new T[this->size];

        for (int i = 0; i < this->length; i++)
            this->data[i] = arr.data[i];

        return *this;
    }

    void removeFirst() {
        if (this->length == 0) throw std::length_error(DA_ZERO_SIZE_MESSAGE);

        for (int i = 0; i < this->length - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->length = this->length - 1;
    }

    void removeLast() {
        if (this->length == 0) throw std::length_error(DA_ZERO_SIZE_MESSAGE);

        this->length = this->length - 1;
    }

    void remove(int index)
    {
        if (index < 0 || index >= this->length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        int n_len = this->length;

        if (index == 0)
            this->removeFirst();
        else if (index == n_len - 1)
            this->removeLast();
        else if (n_len > 1)
        {
            n_len -= 1;
            T* tmp = new T[n_len];
            for (int i = 0; i < index; i++){
                tmp[i] = this->get(i);
            }
            for (int i = index; i < n_len; i++){
                tmp[i] = this->get(i + 1);
            }
            this->size = n_len;
            this->data = tmp;
            this->length = n_len;

        }
        else if (n_len == 1)
        {
            this->size = 0;
            this->length = 0;
            delete this->data;
        }

    }

    void insert(T item, int index)
    {
        if (index < 0 || index > this->length) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        if (index < this->length)
        {
            int n_len = this->length + 1;

            T* tmp = new T[n_len];

            for (int i = 0; i < index; i++)
            {
                *(tmp + i) = *(this->data + i);
            }
            *(tmp + index) = item;
            for (int i = index + 1; i < n_len; i++)
            {
                *(tmp + i) = *(this->data + i - 1);
            }
            delete[]this->data;
            this->data = tmp;
            this->size = n_len;
            this->length = n_len;
        }
        else {
            this->append(item);
        }


    }


    T popLast(){
        if (this->length == 0) throw std::length_error(DA_ZERO_SIZE_MESSAGE);

        T item = this->getLast();
        this->removeLast();
        return item;

    }


    T popFirst(){
        if (this->length == 0) throw std::length_error(DA_ZERO_SIZE_MESSAGE);

        T item = this->getFirst();
        this->removeFirst();
        return item;

    }

    DynamicArray* getSubArray(int startIndex, int endIndex){
        //throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        if ((startIndex < 0) || (endIndex < 0) || (endIndex < startIndex) || (startIndex >= this->length) || (endIndex >= this->length)) throw std::out_of_range(DA_INDEX_OUT_OF_RANGE_MESSAGE);

        DynamicArray<T>* tmp = new DynamicArray<T>((endIndex - startIndex + 1));

        for (int i = startIndex; i <= endIndex; i++)
        {
            tmp->set(this->get(i), i - startIndex);
        }
        return tmp;

    }



    bool operator ==(const DynamicArray<T>& other){
        int t_len = this->length;
        int o_len = other.length;

        if (t_len == o_len)
        {
            for (int i = 0; i < t_len; i++)
            {
                if (this->get(i) != other.get(i))
                    return false;
            }
        }
        else
            return false;
        return true;
    }

    int findSubArray(const DynamicArray<T>& other){
        int t_len = this->length;
        int o_len = other.length;
        DynamicArray<T>* tmp;

        if (t_len == o_len)
        {
            if (*this == other)
                return 0;
            else
                return -1;
        }
        else
        {
            for (int i = 0; i <= t_len - o_len; i++)
            {
                tmp = this->getSubArray(i, i + o_len - 1);
                if (*tmp == other)
                    return i;
            }
            return -1;
        }
    }

    DynamicArray* concat(DynamicArray<T>* list){
        int n_len = this->length + list->length;
        int len_t = this->length;
        int len_l = list->length;
        T* tmp = new T[n_len];
        for (int i = 0; i < len_t; i++)
        {
            *(tmp + i) = this->get(i);
        }
        for (int i = 0; i < len_l; i++)
        {
            *(tmp + len_t + i) = list->get(i);
        }
        DynamicArray<T>* res = new DynamicArray<T>(tmp, n_len);
        return res;
    }

    void printArray(){
        int len = this->length;
        for (int i = 0; i < len; ++i)
        {
            std::cout << *(data + i) << " ";
        }
        std::cout << '\n';
    }

    void map(T(*func)(T))
    {
        int len = this->length;
        for (int i = 0; i < len; i++)
        {
            this->set(i, func(this->get(i)));
        }
    }

    void map(T(*func)(void))
    {
        int len = this->length;
        for (int i = 0; i < len; i++)
        {
            this->set(i, func());
        }
    }

    DynamicArray* where(bool(*func)(T))
    {
        DynamicArray* temp = new DynamicArray<T>();
        int data_t;
        int len = this->length;
        for (int i = 0; i < len; i++)
        {
            data_t = this->get(i);
            if (func(data_t))
            {
                temp->append(data_t);
            }
        }
        return temp;
    }

    T reduce(T(*func)(T))
    {
        T res;
        int len = this->length;
        for (int i = 0; i < len; i++)
        {
            res = func(this->get(i));
        }
        return res;
    }

};


#endif // ARRAY_H