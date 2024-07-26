#include <iostream>

#include <bits/stdc++.h>
using namespace std;

void Sort(int lb,int ub, vector<int> &arr,  vector<int> &res);
void Merge(int lb, int mid, int ub, vector<int> &arr, vector<int> &res); 

vector<int> mergeSort(int n, vector<int> &arr)
{
    int left = 0;
    int right = n-1;
    // int mid = floor( );
    vector<int> res(n);
    Sort(left,right, arr, res);
    return res;
}

void Sort(int lb,int ub, vector<int> &arr,  vector<int> &res){
    if(lb<ub){
        int mid = lb +(ub-lb)/2;
        Sort(lb,mid, arr,res);
        Sort(mid+1,ub, arr,res);
        Merge(lb,mid,ub,arr,res);
    }
}

void Merge(int lb, int mid, int ub, vector<int> &arr, vector<int> &res){
    int i=lb,j=mid+1,k=lb;
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            res[k] = arr[i];
            i++;
        }
        else{
            res[k]=arr[j];
            j++;
        }
        k++;
      
    }
    while(i<=mid){
        res[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ub){
        res[k]=arr[j];
        j++;
        k++;
    }
  for (int p=lb;p<=ub;++p){
    arr[p] = res[p];
  }
  for(int j : arr)
    cout<<j << " ";
  cout<< endl;
}

int main()
{

    int n=5;
    //cin >> n;
    vector<int> arr{ 12, 8, 3, 0, 7};
    //for (int i = 0; i < n; i++)
      //  cin >> arr[i];

    vector<int> sortedArr = mergeSort(n, arr);

    for (int j : sortedArr)
        cout << j << " ";
}
