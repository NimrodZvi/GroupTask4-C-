#include <iostream>

using namespace std;

int bSearch(int arr[], int n, int num);

//Assuming we get an sorted array from largest to smallest values.
int bSearch(int arr[], int n, int num) {
	//Highest number in first cell, lowest number on last cell
	int high = 0, low = n-1, mid;
	while (low >= high) {
		mid = (low + high) / 2;
		if (arr[mid] == num)
		//Return the index value of the call which matches the 'num' value
			return mid;
		if (arr[mid] < num)
			low = mid - 1;
		else
			high = mid + 1;
	}
	//if index wasn't found within the reversed sorted array
	return -1;
}
