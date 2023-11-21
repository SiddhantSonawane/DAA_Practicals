#include<bits/stdc++.h>
using namespace std;

vector<int>subsets;
int numberofsubsets =1;
bool found = false;

void printSubsets()
{
    for(int i=0; i<subsets.size(); i++){
        cout<<subsets[i]<<" ";
    }
    cout<<endl;
}

void sumofsubsets(vector<int>set, vector<int>&subsets, int idx,int target, int n)
{
    if(target==0)
    {
        cout<<"Subset Number "<<numberofsubsets<<" found!"<<endl;
        numberofsubsets++;
        printSubsets();
        found = true;
        return;
    }
    if(idx>=n) return;
    sumofsubsets(set, subsets, idx+1, target, n);
    if(set[idx]<=target)
    {
        subsets.push_back(set[idx]);
        sumofsubsets(set, subsets, idx+1, target-set[idx], n);
        subsets.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter the number of element: ";
    cin>>n;
    vector<int>set(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++) cin>>set[i];

    int target;
    cout<<"Enter the target sum: ";
    cin>>target;

    sumofsubsets(set, subsets, 0, target, n);    
    return 0;
}