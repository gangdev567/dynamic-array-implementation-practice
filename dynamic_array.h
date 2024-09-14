// dynamic_array.h
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int size;

public:
    DynamicArray(int initialCapacity = 2);
    ~DynamicArray();

    void push_back(const T& element);
    T& at(int index);
    const T& at(int index) const;
    int getSize() const;
    int getCapacity() const;
    void resize(int newSize);
    void reserve(int newCapacity);

    class iterator {
    private:
        T* ptr;

    public:
        iterator(T* p) : ptr(p) {}

        T& operator*() const { return *ptr; }
        iterator& operator++() { ++ptr; return * this; }
        bool operator!=(const iterator& other) const {return ptr  != other.ptr; }

        // 추가로 필요한 연산자 오버로드
        iterator& operator--() { --ptr; return *this;}
        bool operator==(const iterator& other) const {return ptr == other.ptr; }
    };

    class const_iterator {
    private:
        const T* ptr;

    public:
        const_iterator(const T* p) : ptr(p) {}

        const T& operator*() const { return *ptr; }
        const_iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
        bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
    };

    // 반복자 생성 함수
    iterator begin() { return iterator(data); }
    iterator end() { return iterator(data + size); }

    // 상수 반복자도 고려할 수 있음
    const_iterator cbegin() const { return const_iterator(data); }
    const_iterator cend() const { return const_iterator(data + size); }

};

#include "dynamic_array.tpp"

#endif //DYNAMIC_ARRAY_H
