// dynamic_array.tpp

template<typename T>
DynamicArray<T>::DynamicArray(int initialCapacity) :
data(new T[initialCapacity]),
capacity(initialCapacity),
size(0) {}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
void DynamicArray<T>::push_back(const T& element) {
    if(size == capacity) {
        resize(capacity * 2);
    }
    data[size] = element;
    size++;
}

template<typename T>
T& DynamicArray<T>::at(int index) {
    if(index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::at(int index) const {
    if(index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template<typename T>
int DynamicArray<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void DynamicArray<T>::resize(int newSize) {
    if(newSize > capacity) {
        T* newData = new T[newSize];
        for(int i = 0; i< size && i < newSize; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newSize;
    }
    size = newSize;
}

template<typename T>
void DynamicArray<T>::reserve(int newCapacity) {
    if(newCapacity > capacity) {
        T* newData = new T[newCapacity];
        for (int i =0; i< size; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}