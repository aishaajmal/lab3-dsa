#include "Array.h"

template<class t>
class myarraylist : public Mylist<t> {
public:
    myarraylist(int size) : Mylist<t>(size) { }

    bool full();
    bool empty();
    bool insertAt(int index, t value);
    bool search(const t& value);
    t last() const; 
    void display();
};

template<class t>
bool myarraylist<t>::full() {
    return this->currentsize == this->maxsize;
}

template<class t>
bool myarraylist<t>::empty() {
    return this->currentsize == 0;
}

template<class t>
bool myarraylist<t>::insertAt(int index, t value) {
    if (index < 0 || index > this->currentsize || this->full()) {
        return false;
    }

    for (int i = this->currentsize; i > index; --i) {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = value;
    this->currentsize++;
    return true;
}

template<class t>
bool myarraylist<t>::search(const t& value) {
    for (int i = 0; i < this->currentsize; ++i) {
        if (this->arr[i] == value) {
            return true;
        }
    }
    return false;
}

template<class t>
t myarraylist<t>::last() const {
    if (!this->empty()) {
        return this->arr[this->currentsize - 1];
    }
    else {
        
        cout << "Error: List is empty." << std::endl;
   
        return t(); 
    }
}
template <class t>
void myarraylist<t>::display() {
    cout << "\n--- MyArrayList Menu ---" << endl;
    cout << "1. Check if the list is empty" << endl;
    cout << "2. Check if the list is full" << endl;
    cout << "3. Insert element at index" << endl;
    cout << "4. Get the last element of the list" << endl;
    cout << "5. Search for an element" << endl;
    cout << "6. Get the current size of the list" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}