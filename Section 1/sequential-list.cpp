#include "sequential-list.h"
#include "iostream"

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    size_ = 0;
    data_ = new DataType[capacity_];

}

SequentialList::~SequentialList()
{
    delete data_;

    data_ = nullptr;
}

unsigned int SequentialList::size() const
{
    return size_;

}


unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if(size_ == 0) {

        return true;
    }

    return false;
}

bool SequentialList::full() const
{
    if(size_ == capacity_) {

        return true;
    }

    else{

        return false;
    }
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{

    if(index > capacity_ -1 || index > size_-1 || index < 0){

        return data_[size_ -1];
    }

    else{

        return data_[index];
    }
}

unsigned int SequentialList::search(DataType val) const
{

    if(size_ !=0) {

        for (int i = 0; i < size_; i++) {

            if (data_[i] == val) {

                return i;
            }
        }
    }

    return size_;
}

void SequentialList::print() const
{
    std::cout<< "[";

    for (int i = 0; i < size_; i++){

        std::cout<< data_[i];

        if(i != size_-1) {

            std::cout << ", ";
        }
    }

    std::cout<< "]" << std::endl;
}

bool SequentialList::insert(DataType val, unsigned int index)
{

    if(size_ + 1 > capacity_ || index > size_ || index < 0){

        return false;
    }

    else if (index == 0 ){

        return insert_front(val);;
    }
    else{

        size_++;

        int i;

        for(i = size_; i> index; i--){

            data_[i] = data_[i-1];

        }
        data_[i] = val;       

        return true;
    }
}
// this is similar to insert however the index we are inserting to is hard set to 0
bool SequentialList::insert_front(DataType val)
{
    if(size_ + 1 > capacity_){

        return false;
    }
    else{
        size_++;

        int i;

        for(i = size_ +1; i>= 0; i--){

            data_[i] = data_[i-1];
        }
        data_[i+1] = val;

        return true;
    }
}

bool SequentialList::insert_back(DataType val)

    if(size_ + 1 > capacity_){

        return false;
    }

    else{

        size_++;
        data_[size_-1] = val;

        return true;
    }
}


bool SequentialList::remove(unsigned int index)
{
    if (size_ == 0 || index < 0 || index > size_ -1) {

        return false;
    }

    else if (index == 0) {

        return remove_front();
    }
    else{

        for(int i = index; i < size_; i++){

            data_[i] = data_[i+1];
        }
        size_--;

        return true;
    }

}

bool SequentialList::remove_front()
{
    if (size_ == 0) {

        return false;
    }
    else{

        for(int i = 0; i < size_; i++){

            data_[i] = data_[i+1];
        }
        
        size_--;

        return true;
    }
}

bool SequentialList::remove_back()
{
    if(size_ == 0){

        return false;
    }
    else {

        data_[size_ - 1] = NULL;
        size_--;

        return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if(index > size_ -1 || index < 0){
        
        return false;
    }
    else{
        data_[index] = val;
    }
}
