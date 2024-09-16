#include <bits/stdc++.h>
using namespace std;

int gcd( int a,int b)
{
    // while (b != 0)
    // {
    //     int remain = a % b;
    //     a = b;
    //     b = remain;
    // }
    // return a;
    
    if ( b == 0) return a;
    return gcd(b,a%b);
}

int main()
{
     
}