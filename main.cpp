#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int binarySearch(const int arr[], int size, int ref) {

    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] == ref) {
            return mid;
        }
        if(ref > arr[mid]) {
            start = mid + 1;
        } else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }

    return -1;
}

int main () {

    int busq = 11;
    int MyArray[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i : MyArray) {
        cout << i << " - ";
    }
    cout << endl;

    if (binarySearch(MyArray, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << binarySearch(MyArray, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }

    DoublyLinkedList MyList = DoublyLinkedList();

    for (int i = 0; i < 10; i++) {
        MyList.insert(i + 1);
    }
    MyList.displayList();

    if (MyList.binarySearch(busq)) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA LISTA" << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }
    MyList.displayList();

    return 0;
}