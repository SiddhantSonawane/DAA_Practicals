#include<bits/stdc++.h>
using namespace std;

int main()
{
    int capacity, n;
    cout<<"Enter the capacity of the knapsack: ";
    cin>>capacity;
    if(capacity<=0)
    {
        cout<<"Insufficient Capacity!!"<<endl;
        return 0;
    }
    cout<<"Enter the number of items: ";
    cin>>n;
    vector<pair<double,double>>pw(n); //profit and weight
    vector<pair<double,int>>ri; //ratio and index of the corresponding item
    cout<<"Enter the Profits and Weights of the items: "<<endl;
    cout<<"Enter Profits: ";
    for(int i=0; i<n; i++)
    {
        cin>>pw[i].first;
    }
    cout<<endl;
    cout<<"Enter Weights: ";
    for(int i=0; i<n; i++)
    {
        cin>>pw[i].second;
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        double ratio = pw[i].first/pw[i].second;
        ri.push_back(make_pair(ratio,i));
    }
    cout<<"\n\n\nThe Data is as Follows: "<<endl;
    cout<<"=============================================================================="<<endl;
    cout<<"Profits(in Rs): ->\t";
    for(int i=0; i<n; i++)
        cout<<pw[i].first<<"\t";
    cout<<"\nWeights(in Kg): ->\t";
    for(int i=0; i<n; i++)
        cout<<pw[i].second<<"\t";
    cout<<"\n\nRatios: ->\t\t";
    for(auto it:ri)
        cout<<it.first<<"\t";
    cout<<"\n";

    sort(ri.rbegin(),ri.rend());
    double profit=0;

    cout<<"******************************************************************************"<<endl;
    cout<<"Current Profit: "<<profit<<endl;
    cout<<"\nInitial Knapsack Capacity: "<<capacity<<endl;
    cout<<"\nItems Available to get Added in Knapsack are(Items are in Sorted Order): "<<endl;
    cout<<"******************************************************************************"<<endl;

    cout<<"Initial Items:"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"|Item\t|Profit\t|Weight\t|Ratio"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<"|"<<i+1<<"\t"<<"|"<<pw[ri[i].second].first<<"\t"<<"|"<<pw[ri[i].second].second<<"\t"<<"|"<<ri[i].first;
        cout<<endl;
    }
    cout<<"---------------------------------------------------";
    cout<<endl;

    cout<<"******************************************************************************"<<endl;
    cout<<"Items Getting Picked are: "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;
    cout<<"Element No.\tWeight\tProfit\tKnapsack Capacity\tTotal Profit"<<endl;

    for(int i=0; i<n; i++)
    {
        if(pw[ri[i].second].second <= capacity)
        {
            profit+=pw[ri[i].second].first;
            capacity-=pw[ri[i].second].second;
        }
        else if(pw[ri[i].second].second > capacity)
        {
            double toadd = (capacity*ri[i].first);
            profit+=toadd;
            break;
        }
        cout<<"|"<<i+1<<"\t\t"<<"|"<<pw[ri[i].second].second<<"\t"<<"|"<<pw[ri[i].second].first<<"\t"<<"|"<<capacity<<"\t\t\t"<<"|"<<profit;
        cout<<endl;
        // cout<<"\tKnapsack Capacity: "<<capacity<<" Total Profit: "<<profit<<endl;
    }
    cout<<"-----------------------------------------------------------------------------------------------"<<endl;


    cout<<"\nTotal Maximum Profit Achieved is: "<<profit<<endl;
    cout<<"Time Complexity is: O(n logn + n) Approx. O(nlogn)";
    cout<<"\n\n"<<endl;
    return 0;
}