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
    int a = 99;
    int i = 0;
    printBinary(a);
    printBinary(~a);
    if ((a & (1 << i)) != 0)
    {
        cout << "Set bit"<<endl;
    }
    else
    {
        cout << "Not Set Bit"<<endl;
    }
    // Bit Set
    printBinary(a | (1<<1));

    // Bit Unset
    printBinary (a& (~(1<<3)));

    // Toggle (XOR)
    printBinary(a^ (1<<2));
    printBinary(a^ (1<<3));

    // Bit Count
    cout<<__builtin_popcount(a)<< endl;
    
    return 0;
}