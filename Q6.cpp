// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 100;
const int rows = 3;

int mapSequences(char strMat[][SIZE], int rows);

int main()
{
	char mapSeq[][SIZE] = { "0000000" , "10101" , "11000001" }; 

	int res = mapSequences(mapSeq, rows);

	cout << "Max sequences found : " << res << endl;
	return 0;
}

int mapSequences(char strMat[][SIZE], int rows)
{
	int maxSeq = 0;

	for (int i = 0; i < rows; i++)
	{
		int currentseqCount = 0;
		int charCount = 1;

		if (strMat[i][0] == '0') // check the first char. if it 0, print 0
		{
			cout << "0";
			currentseqCount++;
		}

		for (int j = 1; strMat[i][j] != '\0'; j++) // loop of the string itself
		{
			if (strMat[i][j] == strMat[i][j - 1])
			{
				charCount++;
			}
			else
			{
				cout << charCount;
				currentseqCount++;
				charCount = 1;
			}
		}
		cout << charCount << endl; // print the last sequence
		currentseqCount++;

		if (currentseqCount > maxSeq) //check the maximum sequence
		{
			maxSeq = currentseqCount;
		}
	}
	return maxSeq;
}
