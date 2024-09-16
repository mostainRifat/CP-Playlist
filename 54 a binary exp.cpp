#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int binExpRec(int a, int b)
{
    if (b == 0)
        return 1;
    long long res = binExpRec(a, b / 2);

    if (b & 1)
        return (a * res * res)%M;
    else
        return (res * res)%M;
}

int binExpItr(int a, int b)
{
    long long ans = 1;

    while(b)
    {
        if(b&1) // denotes last bit is set
        {
            ans = (ans* 1LL*a)%M;
        }
        a = (a* 1LL*a)%M;
        b >>= 1; // B left shift  11001--> 1100
    }
    return ans;
}

int binMultiply (long long a, long long b)
{
    int ans = 0 ;
    while(b>0)
    {
        if(b&1)
        {
            ans = (ans + a) %M ;
        }
        a= (a + a )% M;
        b >>= 1;
    }
}

int main()
{
    int a=2, b=345;
    cout<<binExpRec(a,b)<<endl;
    cout<<binExpItr(a,b)<<endl;

}  