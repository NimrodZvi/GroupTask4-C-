// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
using namespace std;

int const N = 3;

void sortedMatrix(int mat[][N], int rows); //declaration for the sorting function

int main()
{
	int matrix[N][N];

	cout << "Please enter " << N * N << " random numbers : " << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j]; //user's input
		}
	}

	sortedMatrix(matrix, N);
	cout << "----- AFTER SORTING -----" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " "; //print the user's input after the sorting
		}
		cout << endl;
	}
	return 0;
}

void sortedMatrix(int mat[][N], int rows)
{
	int temp;
	int size = rows * N;

	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			// get the current numbers
			int curRow = j / N;
			int curCol = j % N;

			// get the next numbers
			int nextRow = (j + 1) / N;
			int nextCol = (j + 1) % N;

			if (mat[curRow][curCol] > mat[nextRow][nextCol]) //activate the sorting
			{
				temp = mat[curRow][curCol];
				mat[curRow][curCol] = mat[nextRow][nextCol];
				mat[nextRow][nextCol] = temp;
			}
		}
	}
}
