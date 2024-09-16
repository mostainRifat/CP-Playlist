#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n , max = 0, k;
        cin>>n;
        while(n--)
        {
            cin>>k;
            if(k>max)
                max = k;
        }
        cout<<max<<endl;
    }
}