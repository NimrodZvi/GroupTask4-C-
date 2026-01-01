// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

const int SIZE = 101;

void getSentence(char str[]);
void bLanguage(char source[]);
void pigLatin(char source[]);

int main()
{
	char bLangSen[SIZE];
	char pLatSen[SIZE];
	int choise;

	cout << "Welcome to the language convertor !!! " << endl;
	
	do //loop of the menu until the user ask to stop
	{
		cout << "Please choose :" << endl;
		cout << "1 --> Pig-Latin." << endl;
		cout << "2 --> B-Language." << endl;
		cout << "0 --> Finish the program." << endl;

		cin >> choise;
		cin.ignore(); // becouse it's needed to bLanguage function

		if (choise == 1)
		{
			pigLatin(pLatSen);
		}
		else if (choise == 2)
		{
			bLanguage(bLangSen);
		}
		else if (choise == 0)
		{
			cout << "GoodBye !" << endl;
		}
		else
		{
			cout << "Invalid input, please try again" << endl; // if the user enter a number that not in the menu.
		}
	} 
	while (choise != 0);

	return 0;
}

void getSentence(char str[]) // Generic function for enter a sentence
{
	cout << "Please enter a sentence (maximum 100 characters) : " << endl;
	cin.getline(str, SIZE);
}

void bLanguage(char source[])
{
	char dest[SIZE];
	int i = 0;
	int j = 0;

	getSentence(source);

	while (source[i] != '\0')
	{
		if (source[i] == 'a' || source[i] == 'e' || source[i] == 'i' || source[i] == 'o' || source[i] == 'u')
		{
			//enter just if the letter is a/e/i/o/u.
			dest[j] = source[i];
			j++;

			dest[j] = 'b';
			j++;

			dest[j] = source[i];
			j++;
		}
		else // if not continue to the next letter
		{
			dest[j] = source[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0'; //mark the end of the string
	cout << "The output is : " << dest << endl;
}


void pigLatin(char source[])
{
	char dest[SIZE];
	char tempCon[SIZE];
	int tempIndex = 0;
	int i = 0, j = 0;

	bool isStartOfWord = true;
	bool StartWithVowel = false;
	bool foundFirstVowel = false;

	getSentence(source);

	while (source[i] != '\0')
	{
		if (source[i] == ' ')
		{
			if (StartWithVowel == true)
			{
				dest[j] = 'w';
				j++;
				dest[j] = 'a';
				j++;
				dest[j] = 'y';
				j++;
			}
			else
			{
				for (int z = 0; z < tempIndex; z++)
				{
					dest[j] = tempCon[z];
					j++;
				}

				dest[j] = 'a';
				j++;
				dest[j] = 'y';
				j++;
			}

			dest[j] = ' ';
			j++;
			isStartOfWord = true;
			tempIndex = 0;
			foundFirstVowel = false;
		}
		else
		{
			if (isStartOfWord == true)
			{
				if (source[i] == 'a' || source[i] == 'e' || source[i] == 'i' || source[i] == 'o' || source[i] == 'u')
				{
					StartWithVowel = true;
				}
				else
				{
					StartWithVowel = false;
				}
				isStartOfWord = false;
			}
			if (StartWithVowel == true)
			{
				dest[j] = source[i];
				j++;
			}
			else
			{
				if (foundFirstVowel == true)
				{
					dest[j] = source[i];
					j++;
				}
				else
				{
					if (source[i] == 'a' || source[i] == 'e' || source[i] == 'i' || source[i] == 'o' || source[i] == 'u')
					{
						foundFirstVowel = true;
						dest[j] = source[i];
						j++;
					}
					else
					{
						tempCon[tempIndex] = source[i];
						tempIndex++;
					}
				}
			}
		}
		i++;
	}
	if (StartWithVowel == true)
	{
		dest[j] = 'w';
		j++;
		dest[j] = 'a';
		j++;
		dest[j] = 'y';
		j++;
	}
	else
	{
		for (int z = 0; z < tempIndex; z++)
		{
			dest[j] = tempCon[z];
			j++;
		}
		dest[j] = 'a';
		j++;
		dest[j] = 'y';
		j++;
	}
	dest[j] = '\0';
	cout << "The output is : " << dest << endl;
}
