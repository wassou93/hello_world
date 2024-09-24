#include <iostream>

int getInt() {
    return 1000;
}

int main(int, char**){
    int value1 = 700;
    int *pValue2 = &value1;
    // int *pValue3 = &700;

    int *pValue4 = &++value1;
    // int *pValue5 = &value1++;

    // int *pValue5 = &getInt();
}
