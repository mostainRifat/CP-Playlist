#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{
    printBinary(10);
    char B = 'B';
    // Upper to Lower
    char b = B | ' ';

    // Lower to Upper 
    char d = 'd';
    char D = (d & '_');
}