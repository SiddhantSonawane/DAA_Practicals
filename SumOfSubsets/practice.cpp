#include<bits/stdc++.h>
using namespace std;

vector<int>subsets;
int numberOfSubsets = 1;
bool foundSubset = false;

void printSubset()
{
    for(int i=0;i<subsets.size();i++)
    {
        cout<<subsets[i]<<" ";
    }
    cout<<endl;
}

void sumOfSubsets(vector<int>set, vector<int>&subsets, int idx, int n,int target)
{
    if(target==0)
    {
        foundSubset = true;
        cout<<"Subset Number "<<numberOfSubsets<<" found!!"<<endl;
        printSubset();
        numberOfSubsets++;
        return;
    }
    if(idx==n) return;
    sumOfSubsets(set, subsets, idx+1, n, target);
    if(set[idx]<=target)
    {
        subsets.push_back(set[idx]);
        sumOfSubsets(set, subsets, idx+1, n, target-set[idx]);
        subsets.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter The Number of Elements in the Set: ";
    cin>>n;
    vector<int>set(n);
    cout<<"Enter the Elements :";
    for(int i=0;i<n;i++){
        cin>>set[i];
    }

    int target;
    cout<<"Enter the Target Sum you are looking for: ";
    cin>>target;

    sumOfSubsets(set,subsets,0,n,target);

    if(!foundSubset)
    {
        cout<<"No Subset With the given sum found!!"<<endl;
        return 0;
    }else{
        cout<<"Total "<<numberOfSubsets-1<<" Subsets Found!!"<<endl;
    }
    return 0;
}