#include <iostream>
using namespace std;
template <class t>
class Mylist {
protected:
	T* arr;
	int maxsize;
	int currentsize;
public:
	Mylist(int size) :maxsize(size), currentsize(0) {
		arr = new t[maxsize];
	}
	Mylist(const Mylist<T>& other);
	~Mylist();
	virtual  bool full() = 0;
	virtual bool empty() = 0;
	virtual bool insertAt(int index, T value) = 0;
	virtual bool search(const T& value) = 0;
	T last() const;
	virtual void display = 0;
};
template <class t>
Mylist<t>:: Mylist(const Mylist<T>& other) {
    maxsize = other.maxsize;
    currentsize = other.currentsize;
    arr = new T[maxsize];
    for (int i = 0; i < currentsize; ++i) {
        arr[i] = other.arr[i];
    }
}
template <class t>
Mylist<t>::~Mylist() {
	delete[] arr;
}
