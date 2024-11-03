#include "Array.h"

template <class t>
class myarray : public Array<t> {
public: 
    myarray(int size) : Array<t>(size) {}

    void addelementatfirstindex(t);
    void addelementatlastindex(t);
    t removalelementfromend();
    t removeelementFromstart();
    bool isempty();
    bool isfull();
    void display();
};

template <class t>
void myarray<t>::addelementatfirstindex(t element) {
    if (!isfull()) {
        for (int i = currentsize; i > 0; i--) { 
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        currentsize++;
    }
    else {
        cout << "Array is full, cannot add element at first index." << endl;
    }
}

template <class t>
void myarray<t>::addelementatlastindex(t element) {
    if (!isfull()) {
        arr[currentsize] = element;
        currentsize++;
    }
    else {
        cout << "Array is Full, cannot add element at last index." << endl;
    }
}

template <class t>
t myarray<t>::removalelementfromend() {
    if (!isempty()) {
        return arr[--currentsize]; 
    }
    else {
        cout << "Array is empty........" << endl;
        return t(); 
    }
}

template <class t>
t myarray<t>::removeelementFromstart() {
    if (!isempty()) {
        t firstelement = arr[0];
        for (int i = 0; i < currentsize - 1; i++) { 
            arr[i] = arr[i + 1];
        }
        currentsize--;
        return firstelement;
    }
    else {
        cout << "Array is empty........" << endl;
        return t(); 
    }
}

template <class t>
bool myarray<t>::isempty() {
    return currentsize == 0;
}

template <class t>
bool myarray<t>::isfull() {
    return Array::currentsize == Array::maxsize; 
}

template <class t>
void myarray<t>::display() {
    cout << "Max Size: " << maxsize << endl;
    cout << "Current Size: " << currentsize << endl;
    cout << "Elements in the array: ";
    for (int i = 0; i < currentsize; i++) {
        cout << arr[i] << " ";
    }
}