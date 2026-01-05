// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
using namespace std;
#define SIZE 3


void printArr (int arr[][SIZE], int size) {
    // function to print a 2D array at a given size

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

}


void arrSort(int arr[][SIZE], int rows) {
    // function to sort a 2D array using buble sort
    int totalSize = SIZE*rows;

    // bubble sort 

    for (int i=0; i<totalSize; i++) {
        
        for (int j=0 ;j < totalSize - i - 1; j++) {
            // calc first element location
            int currentRow = j / rows;
            int currentColl = j % rows;

            // calc second elemet location
            int nextRow = (j+1) / rows;
            int nextColl = (j+1) % rows;

            // compare and sort if needed (same as buuble sort)
            if (arr[currentRow][currentColl] > arr[nextRow][nextColl]) {
                int temp = arr[currentRow][currentColl];
                arr[currentRow][currentColl] = arr[nextRow][nextColl];
                arr[nextRow][nextColl] = temp;
            }
        }
    }
}

int main() {

    int arr[SIZE][SIZE];
    // recive the array fromt the user
    cout << "Plase enter a matrix the size of " << SIZE << " * " << SIZE << "." << endl;

    for (int i=0;i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            cin >> arr[i][j];
        } 
    }

    // print the array before sorting
    cout << "The arr before soring is: " << endl;
    printArr(arr, SIZE);
    // run the sort func
    arrSort(arr, SIZE);

    cout << "The arr atfer soring is: " << endl;
    // print the array after sorting
    printArr(arr, SIZE);

    return 0;
}