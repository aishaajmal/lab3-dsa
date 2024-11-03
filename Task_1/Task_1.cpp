#include <iostream>
#include "myarray.h" 

int main() {
    myarray<int> arr(5); 

    arr.addelementatfirstindex(50);
    arr.addelementatlastindex(90);

    arr.display();
    cout << "After Removing " << endl;
    arr.removalelementfromend();
    arr.removeelementFromstart();
    arr.display();
    return 0;
}
