// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;

int const SIZE = 50;

int myStr(char s[], char t[]); // declaration for the mystr function

int main()
{
	char mainStr[SIZE];
	char inMain[SIZE];

	cout << "Please enter the main string :" << endl;
	cout << "Attention ! it length can be until " << SIZE << " characters." << endl;

	cin.getline(mainStr, SIZE); //user's input for the main string
	cout << endl;

	cout << "Please enter the 'inMain' string :" << endl;

	cin.getline(inMain, SIZE); // user's input for the second string
	cout << endl;

	int res = myStr(mainStr, inMain);

	cout << "the string " << inMain << " found " << res << " times in " << mainStr;
	return 0;
}

int myStr(char s[], char t[])
{
	int count = 0;
	int lenS = strlen(s); //find the length of string s
	int lenT = strlen(t); //find the length of string t

	for (int i = 0; i < lenS - lenT; i++) // the possisble length
	{
		bool isMatch = true;
		for (int j = 0; j < lenT; j++)
		{
			if (t[j] != s[i+j])
			{
				isMatch = false; // if false, continue to the next index
			}
		}
		if (isMatch == true)
		{
			count++;
		}
	}
	return count;
}
