#include <iostream>

using namespace std;

#define N 3


void sortMatrix(int arr[N][N]);
void bubbleSort(int arr[], int n);
void swapCells(int& num1, int& num2);

void sortMatrix(int arr[N][N]) {
	
    //Insert the values of the 2-dimensional array into a 1-dimensional array
	int arrAssist [N*N];
    int k =0;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            arrAssist[k] = arr[i][j];
            k++;
        }
    }

    //Run the bubble sort of the 1-dimensional array
    bubbleSort(arrAssist, N*N);

    //Insert back the values of the 1-dimensional array into a 2-dimensional array
    k=0;
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            arr[i][j] = arrAssist[k];
            k++;
        }
    }
}



//Assisting Function - Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapCells(arr[j], arr[j + 1]);//
            }
        }
    }
}

//Swap a spesific cell value
void swapCells(int& num1, int& num2) {
   int temp; 
    temp = num1;
    num1 = num2;
    num2 = temp;
}


