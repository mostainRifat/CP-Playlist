// 50^64^32
#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;

int binExpItr(int a, int b, int m)
{
    long long ans = 1;

    while(b)
    {
        if(b&1) // denotes last bit is set
        {
            ans = (ans* 1LL*a)%m;
        }
        a = (a* 1LL*a)%m;
        b >>= 1; // B left shift  11001--> 1100
    }
    return ans;
}

int main()
{
    cout<<binExpItr(50,binExpItr(64,32, M-1), M) <<endl;
    return 0 ;
}