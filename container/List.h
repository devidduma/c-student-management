#ifndef LIST_H
#define LIST_H

template <class T>
struct ListNode {
    T* data;
    ListNode<T>* next;
    ListNode<T>* previous;

    // constructor
    ListNode() :
        next(nullptr),
        previous(nullptr)
    {}
};

template <class T>
struct List {
    ListNode<T> *head;
    ListNode<T> *tail;
    int size;

    // constructor
    List() :
        head(nullptr),
        tail(nullptr),
        size(0)
    {}
    // copy constructor
    List(const List<T>& list) :
            head(list.head),
            tail(list.tail),
            size(list.size)
    {}
    List& operator= (const List& list) {
        this->head = list.head;
        this->tail = list.tail;
        this->size = list.size;
        return *this;
    }

};

template <class T>
// Default parameter
List<T> push_back(List<T>& list, T* data = new T()) {

    // create new Element
    ListNode<T>* newElement = new ListNode<T>();
    newElement->data = data;
    // if list is empty
    if(list.head == nullptr && list.tail == nullptr) {
        //update head and tail
        list.head = list.tail = newElement;
    } else {
        //head does not need update
        // doubly link elements in the end
        list.tail->next = newElement;
        newElement->previous = list.tail;
        //update tail
        list.tail = list.tail->next;
    }
    //update size
    list.size++;

    return list;
}


// Function Polymorphism
template <class T>
List<T> push_back(List<T>& list, List<T> data) {

    // if list is empty
    if(list.head == nullptr && list.tail == nullptr) {
        list = data;
        //head, tail, size automatically updated
    } else {
        //head does not need update
        // doubly link elements in the end
        list.tail->next = data.head;
        data.head.previous = list.tail;
        //update tail
        list.tail = data.tail;
        //update size
        list.size += data.size;
    }

    return list;
}

template <class T>
List<T> pop_back(List<T>& list) {
    // if list is empty
    if(list.head == nullptr && list.tail == nullptr) {
        return list;
    } else if(list.size == 1) {
        // delete
        delete list.head;
        // update head, tail, size
        list.head = list.tail = nullptr;
        list.size = 0;
    } else {
        // update tail and delete
        list.tail = list.tail->previous;
        delete list.tail->next;
        list.tail->next = nullptr;
        // update size
        list.size--;
    }
}

#endif