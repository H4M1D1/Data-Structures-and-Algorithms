#include "doubly-linked-list.h"
#include "iostream"
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;

    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
	head_ = nullptr;
	tail_ = nullptr;

	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head_) {

        Node* temp = head_;

        head_ = head_ -> next;

        delete temp;
    }
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    return size_ == 0;
}

bool DoublyLinkedList::full() const
{
    return size_ == CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    if (size_ == 0 || index < 0 || index >= size_) {

        return tail_-> value;
    }

    Node* returnNode = getNode(index);

    return returnNode -> value;
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* current = head_;

    for (int i = 0; i < size_; i++) {

        if (current -> value == value) {

            return i;
        }

        current = current -> next;
    }

    return size_;
}

void DoublyLinkedList::print() const
{
    if (size_ == 0) {

        cout << head_ -> value << endl;

    } else {

        Node* current = head_ -> next;

        for (int i = 0; i < size_; i++) {

            cout << current -> value << endl;

            current = current -> next;
        }
    }
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    Node* current = head_;

    for (int i = 0; i <= index; i++) {

        if (i == index) {

            return current;
        }
        current = current -> next;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    if ((empty() && index != 0) || index > size_) {

        return false;
    }
    if (index == size_) {

        return insert_back(value);
    }

    if (index == 0) {

        return insert_front(value);
    }

    Node* current = getNode(index);
    Node* newNode = new Node(value);

    newNode -> prev = current -> prev;
    newNode -> next = current;

    current -> prev -> next = newNode;
    current -> prev = newNode;

    size_++;

    return true;
}

bool DoublyLinkedList::insert_front(DataType value)
{
    if (size_ == CAPACITY) {

        return false;
    }

    Node* newNode = new Node(value);

    if (size_ == 0) {

        head_ = newNode;
        tail_ = newNode;

    } else {

        head_ -> prev = newNode;

        newNode -> next = head_;

        head_ = newNode;
    }

    size_++;

    return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    if (size_ == CAPACITY) {

        return false;
    }

    Node* newNode = new Node(value);

    if (size_ == 0) {

        return insert_front(value);
    } else {

        tail_ -> next = newNode;

        newNode -> prev = tail_;

        tail_ = newNode;
    }

    size_++;

    return true;
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (index >= size_ || index < 0) {

        return false;
    }

    if (index == 0) {

        return remove_front();
    }
    if (index == size() - 1) {

        return remove_back();
    }

    Node* current = getNode(index);

    current -> next -> prev = current -> prev;
    current -> prev -> next = current -> next;

    delete current;

    size_--;

    return true;
}

bool DoublyLinkedList::remove_front()
{
    if (size_ == 0) {

        return false;
    }

    head_ = head_ -> next;

    if (head_) {

        head_ -> prev = NULL;
    } else {

        tail_ = NULL;
    }

    size_--;

    return true;
}

bool DoublyLinkedList::remove_back()
{
    if (size_ == 0) {

        return false;
    }

    tail_ = tail_ -> prev;

    if (tail_) {

        tail_ -> next = NULL;
    } else {

        head_ = NULL;
    }

    size_--;

    return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if ((size_ == 0 && index != 0) || index > size_) {

        return false;
    } else {

        Node* current = getNode(index);

        current -> value = value;

        return true;
    }
}
