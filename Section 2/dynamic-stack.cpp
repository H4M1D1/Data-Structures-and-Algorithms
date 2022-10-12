#include "dynamic-stack.h"
#include "iostream"
#include "climits"
using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = INT_MAX;

DynamicStack::DynamicStack() {
    init_capacity_ = 16; // initial capacity is 16
    capacity_ = 16;
    size_ = 0;
    items_ = new StackItem[init_capacity_];
}

DynamicStack::DynamicStack(unsigned int capacity){
    init_capacity_ = capacity;
    capacity_ = capacity;
    size_ = 0;
    items_ = new StackItem[init_capacity_];
}

DynamicStack::~DynamicStack() {
    delete [] items_;
}

bool DynamicStack::empty() const {
    return size_ == 0;
}

int DynamicStack::size() const {
    return size_;
}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) {
        capacity_ *= 2; // double capacity
        StackItem* temp = new StackItem[capacity_];
        for (int i = 0; i < size_; i++) {
            temp[i] = items_[i];
        }
        items_ = temp;
    }

    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop() {
    if (size_ == 0) {
        return DynamicStack::EMPTY_STACK;
    }

    size_--;

    if (size_ <= capacity_/4 && capacity_/2 >= init_capacity_) {
        capacity_ /= 2; // capacity halved
        StackItem* temp = new StackItem[capacity_];
        for (int i = 0; i < size_; i++) {
            temp[i] = items_[i];
        }
        items_ = temp;
    }

    return items_[size_];
}

DynamicStack::StackItem DynamicStack::peek() const {
    if (size_ == 0) {
        return DynamicStack::EMPTY_STACK;
    }

    return items_[size_ - 1];
}

void DynamicStack::print() const {
    if (size_ == 0) {
        cout << DynamicStack::EMPTY_STACK << endl;
        return;
    }

    for (int i = size_ - 1; i >= 0; i--) {
        cout << items_[i] << ", ";
    }
    cout << endl;
    return;
}
