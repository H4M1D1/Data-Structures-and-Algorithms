#include "circular-queue.h"
#include "iostream"
#include "climits"
using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = INT_MAX;


CircularQueue::CircularQueue() {
    capacity_ = 16;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue() {
    delete [] items_;
}

bool CircularQueue::empty() const {
    return size_ == 0;
}

bool CircularQueue::full() const {
    return size_ == capacity_;
}

int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::enqueue(QueueItem value) {
    if (size_ == capacity_) {
        return false;
    }

    items_[tail_] = value;
    size_++;
    tail_ = (tail_ + 1) % capacity_;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (size_ == 0) {
        return CircularQueue::EMPTY_QUEUE;
    }

    CircularQueue::QueueItem returnItem = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;
    return returnItem;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (size_ == 0) {
        return CircularQueue::EMPTY_QUEUE;
    }

    return items_[head_];
}

void CircularQueue::print() const {
    if (size_ == 0) {
        cout << CircularQueue::EMPTY_QUEUE << endl;
        return;
    }

    for (int i = 0; i < size_; i++) {
        cout << items_[i] << ", ";
    }
    cout << endl;
    return;
}
