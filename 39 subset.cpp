#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets;
int n;

void genarate(vector<int> &subset, int i, vector<int> &nums)
{
    if ( i == n )
    {
        subsets.push_back(subset); 
        return ;
    }
    // ith element not in subset
    genarate(subset, i + 1, nums);

    // in the subset
    subset.push_back(nums[i]);
    genarate(subset, i + 1 , nums);
    subset.pop_back();
}

int main()
{
    cin>>n;
    vector<int>nums(n);

    for(int i=0 ; i<n;i++)
    {
        cin>>nums[i];   
    }
    vector<int>empty;
    genarate(empty , 0 , nums);

    for(auto subset: subsets)
    {
        for(auto ele: subset)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}