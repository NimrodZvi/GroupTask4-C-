// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
using namespace std;
#define SIZE 10

int bSearch(int arr[], int size, int num) {
    // binary search for num in arr arr[], when arr is sorted rtl in reciding seq
    int low=0, high = size-1, mid;

    // run until low and high meet
    while (low <= high) {
        mid = (low+high) / 2;

        // when num is found at mid, return mid
        if (arr[mid] == num) {
            return mid;
        }
        // if num > mid, search at the lower half (the opasite of normal binary search)
        if (arr[mid] < num ) {
            high = mid -1;
        }
        // if num < mid, serach at the upper half (the opasite of normal binary search)
        else {
            low = mid + 1;       
        }
    }

    // if not found return -1
    return -1;
}


int main() {
    int arr[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int num = 1;
    int foundIndex = bSearch(arr, SIZE, num);
    return 0;
}