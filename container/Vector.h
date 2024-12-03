#ifndef VECTOR_H
#define VECTOR_H

template<class T>
struct Vector {
    T* data;
    int size;
    int capacity;

    // constructor
    Vector() :
        data(new T[4]),
        size(0),
        capacity(4)
    {}
};

template <class T>
// Default Parameter
Vector<T> push_back(Vector<T>& vector, T* data = new T()) {
    vector.data[vector.size++] = *data;

    if(vector.size == vector.capacity) {
        T* newData = new T[vector.capacity*2];
        for(int i = 0; i < vector.capacity; i++) {
            newData[i] = vector.data[i];
        }
        vector.data = newData;
        vector.capacity *= 2;
    }

    return vector;
}

#endif