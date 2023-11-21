#include<bits/stdc++.h>
using namespace std;

// void merge(vector<pair<double, int>>& arr, int l, int m, int r) {
//     int n1 = m - l + 1;
//     int n2 = r - m;

//     vector<pair<double, int>> L(n1);
//     vector<pair<double, int>> R(n2);

//     for (int i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];

//     int i = 0;
//     int j = 0;
//     int k = l;

//     while (i < n1 && j < n2) {
//         if (L[i].first > R[j].first) { // Reverse sort condition
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(vector<pair<double, int>>& arr, int l, int r) {
//     if (l < r) {
//         int m = l + (r - l) / 2;

//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);

//         merge(arr, l, m, r);
//     }
// }
int main()
{
    int capacity, items;
    cout<<"Enter capacity: "<<endl;
    cin >> capacity;
    cout<<"Enter items: "<<endl;
    cin >> items;

    vector<pair<double,double>>pw(items);
    vector<pair<double,int>>ri;

    cout<<"Enter profits of the items: "<<endl;
    for(int i=0; i<items; i++)
    {
        cin>>pw[i].first;
    }
    cout<<"Enter weights of the items: "<<endl;
    for(int i=0; i<items; i++)
    {
        cin>>pw[i].second;
    }

    for(int i=0; i<items; i++)
    {
        double ratio = pw[i].first/pw[i].second;
        ri.push_back(make_pair(ratio,i));
    }

    sort(ri.rbegin(),ri.rend());
    // mergeSort(ri, 0, items - 1);

    double profit =0;
    for(int i=0;i<items; i++)
    {
        if(pw[ri[i].second].second<=capacity)
        {
            profit += pw[ri[i].second].first;
            capacity -= pw[ri[i].second].second;
        }
        else
        {
            double fractionalprofit = capacity*ri[i].first;
            profit += fractionalprofit;
            break;
        }
    }
    cout<<"profit: "<<profit<<endl;
    return 0;
}