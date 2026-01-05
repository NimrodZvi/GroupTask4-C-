

#include <iostream>
#include <string.h>
using namespace std;


int findWordLen(char str[], int start) {
    //find the length of a word
    int counter = 0, i=0;


    while (str[i+start]!=' ' && str[i+start] != '\0' && str[i+start] != '.') {
        counter++;
        i++;
    }
    return counter;
}

bool isVowelLetter (char c) {
    // retrun true if a charcter is a, e, i, u, o
    if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') {
        return true;
    }

    return false;
}


void strToPigLatin (char str[]) {
    int strLen = strlen(str);

    for (int i=0;i<strLen;i++) {
        // find the word len
        int wordLen = findWordLen(str, i);
        int wordEnd = i + wordLen, wordStart = i;

        // if word starts in a e i u o
        if (isVowelLetter(str[wordStart])) {
            // print the word
            for(int j=wordStart; j<=wordEnd-1; j++) {
                cout << str[j];
            }
            // add in way
            cout << "way ";
        }
        
        // if word does not start with a e i u o
        else {
            
            // new string to add at the end of the sentence
            char toAdd[20];
            int counter = 0;
            for (int j=wordStart; j<=wordEnd; j++) {

                if (isVowelLetter(str[j])) {
                    
                    //print the rest of the sentence
            
                    for (int k=j; k<wordEnd; k++) {
                        cout << str[k];
                    }
                    // stop the loop by seting j to word end
                    j = wordEnd+1;

                }

                // if char at str[j] is not a vowel
                else {
                    toAdd[counter] = str[j];
                    counter++;
                }

            }

            // print the rest of word
            for (int j=0; j<=counter; j++) {
                cout << toAdd[j];
            }

            // add in ay and a space in the end
            cout << "ay" << " ";
        }

        // skip to the next word
        i += wordLen;
    }

    // print a comma and a new line
    cout << "." << endl;
}


void strToBLang (char str[]) {
    // turn str to b lang

    // go over the string, find if char is a vowel and if a vowel print b+char(the vowel found.)
    for (int i=0; i<strlen(str); i++) {
        cout << str[i];
        if ( isVowelLetter(str[i])) {
            cout << 'b' << str[i];
        }
    }

    cout << endl;

}



int main() {
    bool selectFin = 1;

    while (selectFin) {
        // print the menu
        char strr[100] = "This is a test sentence.";
        cout << "Please choose: " << endl;
        cout << "1 - Pig-Latin" << endl;
        cout << "2 - B-Language" << endl;
        cout << "0 - finish" << endl;
        cout << ">> ";

        int userInput;
        cin >> userInput;

        if (userInput == 0) {
            selectFin = 0;
        }

        else if (userInput == 1) {
            char str[100];
            cin.ignore();
            cin.getline(str, 100);
            strToPigLatin(str);
        }

        else if (userInput == 2) {
            char str[100];
            cin.ignore();
            cin.getline(str, 100);
            strToBLang(str);
        }
    }
    return 0;
}