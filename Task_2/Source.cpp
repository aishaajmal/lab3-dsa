#include <iostream>
#include "Array.h"
#include "mylist.h"
using namespace std;

int main() {
    int size;
    cout << "Enter the initial size of the list: ";
    cin >> size;

    
    myarraylist<int> list(size);

   
    list.display();

    return 0;
}
