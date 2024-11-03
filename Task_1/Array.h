#include <iostream>
using namespace std;

template <class t>
class Array {
protected:
    t* arr;
    int maxsize;
    int currentsize = 0;
public:
    virtual void addelementatfirstindex(t) = 0;
    virtual void addelementatlastindex(t) = 0;
    virtual t removalelementfromend() = 0;
    virtual t removeelementFromstart() = 0;
    virtual bool isempty() = 0;
    virtual bool isfull() = 0; 

    Array(int);
    virtual ~Array();
};

template <class t>
Array<t>::Array(int size) : maxsize(size), currentsize(0) {
    arr = new t[maxsize];
}

template <class t>
Array<t>::~Array() {
    delete[] arr;
}
