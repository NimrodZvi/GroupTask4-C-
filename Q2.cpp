// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
using namespace std;

int const SIZE = 10;

int bSearch(int arr[], int size, int num); //declaration for binary search function

int main()
{
	int num;
	int array[SIZE];

	cout << "Please enter a number : " << endl;
	cin >> num;
	cout << "Please enter " << SIZE << " sorted numbers, from the biggest to the smallest :" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cin >> array[i]; //user's input
	}

	int res = bSearch(array, SIZE, num);

	if (res == -1)
	{
		cout << "The number " << num <<  " is not found in the array !" << endl;
	}
	else
	{
		cout << "The number " << num << " is found in the array !";
	}


}

int bSearch(int arr[], int size, int num)
{
	int left = 0, right = size - 1, mid; // left is the biggest number & right is the lowest number

	while (left <= right)
	{
		mid = (left + right) / 2; // calculate the starting mid number

		if (arr[mid] == num)
		{
			return mid;
		}
		if (arr[mid] < num)
		{
			right = mid -1;
		}
		else
		{
			left = mid +1;
		}
	}
	return -1; // if the number not found in the array --> return -1
}
