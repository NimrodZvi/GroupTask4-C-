#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100

int countSeq(char str[], char c, int location) {
    // count a seq in a str
    int counter = 0;
    for (int i=location; i<strlen(str); i++) {
        // go over a str from x to y, as long as the char c is found +1 to counter
        if (str[i]==c) {
            counter++;
        }

        else {
            // when the seq is broken
            return counter;
        }
    }
    return counter;
}



int mapSequences(char strMat[][SIZE] ,int rows) {
    // var to find max seq amount
    int maxSeqNum = 0;

    for (int row=0;row<rows; row++) {
        int seqCounter = 0, seqSum = 0;
        
        for (int j=0;j<strlen(strMat[row]); j++) {
            int seqLen = countSeq(strMat[row], strMat[row][j], j);
            seqSum += seqLen;
            seqCounter++;
            seqSum *= 10;
            j += seqLen-1;
        }

        if (seqCounter > maxSeqNum) {
            maxSeqNum = seqCounter;
        }

        // print the shortened str


        // if str starts with a '0' print a zero
        if (strMat[row][0] == '0') {
            cout << "0";
        }

        // print the shotened seq (div by ten to remove one extra zero)
        cout << seqSum / 10 << endl;
    }

    return maxSeqNum;
}

int main() {
    const int rows = 3;
    char strMat[rows][SIZE] = {"0000000", "10101", "11000001"};
    cout << mapSequences(strMat, rows) << endl;

    return 0;
}