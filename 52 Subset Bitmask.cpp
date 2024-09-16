#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>subsets(vector<int>& nums)
{
    int n= nums.size(  );
    //cout<<n;
    int subset_count = (1<<n);
    vector<vector<int>>subsets;

    for(int mask = 0 ; mask<subset_count ; mask++)
    {
        vector<int>subset;
        for(int i =0 ;i<n;i++)
        {
            if((mask & (1<<i)) != 0){
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

int main()
{
     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0 ;i<n;i++)
     {
        cin>>v[i];
     }
     auto ssubsets = subsets(v);

     for(auto subset : ssubsets)
     {
        for(int ele : subset)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
     }
}