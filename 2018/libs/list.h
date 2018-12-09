//
// Created by kyle on 12/9/18.
//

#ifndef ADVENT_LIST_H
#define ADVENT_LIST_H

template <typename T>
class ListNode {
public:
    ListNode(T value);

    T value;
    ListNode<T>* next;
};

template <typename T>
class List {
public:
    List();

    void add(T val);
    size_t count();
private:
    ListNode<T>* head = NULL;
    ListNode<T>* tail = NULL;
};

template <typename T>
ListNode<T>::ListNode(T value)
{
    this->value = value;
}

template <typename T>
void List<T>::add(T value)
{
    auto new_node = new ListNode<T>(value);

    if (NULL == this->head) {
        this->head = new_node;
        this->tail = new_node;
    } else {
        this->tail->next = new_node;
        this->tail = new_node;
    }
}

template <typename T>
size_t List<T>::count()
{
    size_t count = 0;
    ListNode<T>* ptr = this->head;

    while (NULL != ptr) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

template <typename T>
List<T>::List()
{
    this->head = NULL;
    this->tail = NULL;
}


#endif //ADVENT_LIST_H
