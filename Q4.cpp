// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 50;

void printDecrypted(char encriptedStr[]);

int main()
{
	char encriptedToDecrypted[SIZE];

	cout << "Please enter an encripted string : " << endl;
	cin.getline(encriptedToDecrypted, SIZE); //user's input to the encripted string

	cout << "-------------------------------" << endl;

	cout << "----- YOUR DECRYPTED OUTPUT IS : -----" << endl;

	printDecrypted(encriptedToDecrypted);
	cout << endl;
	return 0;
}

void printDecrypted(char encriptedStr[])
{
	int lenStr = strlen(encriptedStr); // using strlen to get the length of the string
	for (int i = lenStr - 1; i >= 0; i--)
	{
		if (encriptedStr[i] >= 65 && encriptedStr[i] <= 90 || encriptedStr[i] >= 97 && encriptedStr[i] <= 122 || encriptedStr[i] >= '0' && encriptedStr[i] <= '9') // print just the letter by using the ASCII table
		{
			cout << encriptedStr[i];
		}
	}
}
