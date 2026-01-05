// Name - Nimrod Zvi, ID - 211905294
// Name - Omri Segal, ID - 209309061
// Name - Tzur Yoselzon, ID - 203349881

#include <iostream>
#include <string.h>
using namespace std;

int mystr(char s[], char t[]) {
    // func to find how many times string t occors in string s

    // find the len of both string and decalre a counter var
    int sLen = strlen(s), tLen = strlen(t), counter = 0;

    // if s len is bigger than one, its needed to remove to not read other parts in memory
    // run a loop in string s
    for (int i=0; i< sLen - (tLen-1); i++) {
        // decalare a bool var to later use if string s is in string t
        bool sInt = true;
        // run a loop for the t string and go forward in string s
        for (int j=0; j<tLen; j++) {
            if (t[j] != s[i+j]) {
                // if char is not the same, sInt is false
                sInt = false;
            }
        }

        // add +1 to the counter if string found
        if (sInt) {
            counter++;
        }
    }

    return counter;
}


int main() {
    char s[] = "abracadabra";
    char t[] = "ra";

    cout << mystr(s, t) << endl;

    return 0;
}