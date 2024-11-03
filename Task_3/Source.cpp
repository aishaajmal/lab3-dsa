#include <iostream>
using namespace std;

template <typename T>
class CustomList {
private:
    T* list;
    int size;

public:
    CustomList(T arr[] = nullptr, int s = 0) : size(s) {
        list = new T[size];
        for (int i = 0; i < size; i++) {
            list[i] = arr[i];
        }
    }

    CustomList(const CustomList& other) {
        size = other.size;
        list = new T[size];
        for (int i = 0; i < size; i++) {
            list[i] = other.list[i];
        }
    }

    ~CustomList() {
        delete[] list;
    }

    bool isPrime(T n) {
        if (n <= 1) return false;
        for (T i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    T sum_ofPrime() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            if (isPrime(list[i])) {
                sum += list[i];
            }
        }
        return sum;
    }

    T secondMaxEven() {
        T maxEven = -1, secondMaxEven = -1;
        for (int i = 0; i < size; i++) {
            if (list[i] % 2 == 0) {
                if (list[i] > maxEven) {
                    secondMaxEven = maxEven;
                    maxEven = list[i];
                }
                else if (list[i] > secondMaxEven && list[i] != maxEven) {
                    secondMaxEven = list[i];
                }
            }
        }
        return secondMaxEven;
    }

    T secondMinOdd() {
        T minOdd = INT_MAX, secondMinOdd = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (list[i] % 2 != 0) {
                if (list[i] < minOdd) {
                    secondMinOdd = minOdd;
                    minOdd = list[i];
                }
                else if (list[i] < secondMinOdd && list[i] != minOdd) {
                    secondMinOdd = list[i];
                }
            }
        }
        return secondMinOdd;
    }

    void printDuplicates() {
        cout << "Duplicate elements: ";
        for (int i = 0; i < size; i++) {
            bool isDuplicate = false;
            for (int j = i + 1; j < size; j++) {
                if (list[i] == list[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (isDuplicate) {
                cout << list[i] << " ";
            }
        }
        cout << endl;
    }

    void rotateClockwise(int r) {
        int mid = size / 2;
        T* firstHalf = new T[mid];
        T* secondHalf = new T[size - mid];

        for (int i = 0; i < mid; i++) firstHalf[i] = list[i];
        for (int i = mid; i < size; i++) secondHalf[i - mid] = list[i];

        for (int i = 0; i < r; i++) {
            T temp1 = firstHalf[mid - 1];
            for (int j = mid - 1; j > 0; j--) firstHalf[j] = firstHalf[j - 1];
            firstHalf[0] = temp1;

            T temp2 = secondHalf[size - mid - 1];
            for (int j = size - mid - 1; j > 0; j--) secondHalf[j] = secondHalf[j - 1];
            secondHalf[0] = temp2;
        }

        for (int i = 0; i < mid; i++) list[i] = firstHalf[i];
        for (int i = mid; i < size; i++) list[i] = secondHalf[i - mid];

        delete[] firstHalf;
        delete[] secondHalf;
    }

    void rotateAntiClockwise(int rt) {
        int mid = size / 2;
        T* firstHalf = new T[mid];
        T* secondHalf = new T[size - mid];

        for (int i = 0; i < mid; i++) firstHalf[i] = list[i];
        for (int i = mid; i < size; i++) secondHalf[i - mid] = list[i];

        for (int i = 0; i < rt; i++) {
            T temp1 = firstHalf[0];
            for (int j = 0; j < mid - 1; j++) firstHalf[j] = firstHalf[j + 1];
            firstHalf[mid - 1] = temp1;

            T temp2 = secondHalf[0];
            for (int j = 0; j < size - mid - 1; j++) secondHalf[j] = secondHalf[j + 1];
            secondHalf[size - mid - 1] = temp2;
        }

        for (int i = 0; i < mid; i++) list[i] = firstHalf[i];
        for (int i = mid; i < size; i++) list[i] = secondHalf[i - mid];

        delete[] firstHalf;
        delete[] secondHalf;
    }

    void displayList() {
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 4, 8, 6, 8, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    CustomList<int> myList(arr, size);

    int choice, rotateTimes;

    do {
        cout << "\nMenu:\n";
        cout << "1. Sum of prime numbers\n";
        cout << "2. Find second maximum even number\n";
        cout << "3. Find second minimum odd number\n";
        cout << "4. Print duplicates\n";
        cout << "5. Rotate clockwise\n";
        cout << "6. Rotate anti-clockwise\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Sum of prime numbers: " << myList.sum_ofPrime() << endl;
            break;
        case 2:
            cout << "Second maximum even number: " << myList.secondMaxEven() << endl;
            break;
        case 3:
            cout << "Second minimum odd number: " << myList.secondMinOdd() << endl;
            break;
        case 4:
            myList.printDuplicates();
            break;
        case 5:
            cout << "Enter number of rotations: ";
            cin >> rotateTimes;
            myList.rotateClockwise(rotateTimes);
            cout << "List rotated clockwise.\n";
            break;
        case 6:
            cout << "Enter number of rotations: ";
            cin >> rotateTimes;
            myList.rotateAntiClockwise(rotateTimes);
            cout << "List rotated anti-clockwise.\n";
            break;
        case 7:
            cout << "Current list: ";
            myList.displayList();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
