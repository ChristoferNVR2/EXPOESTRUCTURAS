#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int sequentialSearch(const int arr[], int size, int ref) {
    for (int i = 0; i < size; i++) {
        if (ref == arr[i]) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int arr[], int size, int ref) {

    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;

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

int recursiveSearch(const int arr[], int start, int end, int ref) { // NOLINT(misc-no-recursion)

    int mid = (end + start)/2;

    if (arr[mid] == ref) {
        return mid;
    }

    if (start > end) {
        return -1;
    }

    if (ref < arr[mid]) {
        return recursiveSearch(arr, start, mid - 1, ref);
    } else {
        return recursiveSearch(arr, mid + 1, end, ref);
    }
}

int main () {

    int busq = 11;

    int MyArray[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i : MyArray) {
        cout << i << " - ";
    }
    cout << endl;


    if (sequentialSearch(MyArray, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << sequentialSearch(MyArray, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }

    if (binarySearch(MyArray, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << binarySearch(MyArray, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }

    if (recursiveSearch(MyArray,0, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << recursiveSearch(MyArray, 0, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }






    DoublyLinkedList MyList = DoublyLinkedList();

    for (int i = 0; i < 10; i++) {
        MyList.insert(i + 1);
    }
    MyList.displayList();

    if (MyList.sequentialSearch(busq) != 0) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA POSICION " << MyList.sequentialSearch(busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }

    if (MyList.binarySearch(busq)) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA LISTA" << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }

    if (MyList.recursiveSearch(busq)) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA LISTA" << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }


    return 0;
}
