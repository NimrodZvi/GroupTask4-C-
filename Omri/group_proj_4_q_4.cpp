// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;

bool isLetterNum ( char c) {
    // func to check if char is number of a letter (capital and lower)
    if (c >= '0' && c <= '9') {
        return true;
    }
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}

void printDecrypted(char encriptedStr[]) {
    // print a decoded string 

    int slen = strlen(encriptedStr), counter=0;
    char newStr[slen];
    
    for (int i=0; i<slen; i++) {
        // if the char in location i of encriptedStr
        if (isLetterNum(encriptedStr[i]) ) {
            newStr[counter] = encriptedStr[i];
            counter++;
        }
    }
    // stop the string the the counter
    newStr[counter] = '\0';

    // reverse the string
    int start = 0, end = strlen(newStr) - 1;

    while (start < end) {
        // swap in the string using the same basic var swap
        char temp = newStr[start];
        newStr[start] = newStr[end];
        newStr[end] = temp;

        // move start and end 
        start++;
        end--;
    }


    // print the new string to the user
    cout << newStr << endl;


}


int main() {
    char arr[] = "3y!!roe$&hT+* -gnaB gi#B eh@T";
    printDecrypted(arr);
}