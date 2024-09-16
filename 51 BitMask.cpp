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
    int n;
    cin>>n;
    vector<int> masks(n, 0);

    for(int i=0 ; i<n;i++)
    {
        int num_workers;
        cin>>num_workers;
        int mask =0 ;
        for(int j=0 ;j<num_workers; j++)
        {
            int day;
            cin>>day;
            mask = (mask | (1<< day));
        }
        masks[i] = mask;
    }
    
    for(int i=0 ; i< n; i++)
    {
        cout<<masks[i]<<endl;
        printBinary(masks[i]);
    }
    int max_days = 0;
    for(int i =0 ;i<n ;i++)
    {
        for(int j =i+1 ; j<n;j++)
        {
            int intersection = masks[i] & masks[j];
            int common = __builtin_popcount(intersection);
            cout<<i<<" "<<j << " " << common <<endl;
            max_days = max(max_days, common);
        }
    }
    cout<<max_days<<endl;
}