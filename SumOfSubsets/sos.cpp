#include<bits/stdc++.h>
using namespace std;

vector<int>subset;
bool f = false;
int noofsubsets=1;

void printsubset(){
    for(int i=0; i<subset.size(); i++){
        cout<<subset[i]<<" ";
    }
    cout<<endl;
}

void findsubsets(vector<int>set, vector<int>&subset, int i, int n, int target)
{
    if(target==0){
        f=true;
        cout<<"Subset Number "<<noofsubsets<<" found!"<<endl;
        noofsubsets++;
        printsubset();
        return;
    }
    if(i==n) return;
    findsubsets(set,subset, i+1, n, target);
    if(set[i]<=target){
        subset.push_back(set[i]);
        findsubsets(set, subset, i+1, n, target-set[i]);
        subset.pop_back();
    }
}

int main()
{
    int n;
    cout<<"Enter the Number of Elements in the array: ";
    cin >> n;
    vector<int>set(n);
    cout<<"Enter the Array Elements: ";
    for(int i=0; i<n; i++){
        cin>>set[i];
    }
    int target;
    cout<<"Enter the Target Sum you are looking for: ";
    cin>>target;
    findsubsets(set, subset, 0, n, target);
    if(!f){
        cout<<"No Subset with the given target sum found!"<<endl;
    }
    return 0;
}