#include<bits/stdc++.h>
using namespace std;

void merge_sorted_arr(vector<int> &arr1,int n,vector<int> &arr2,int m){
    int it1 = n-1; /* Iterator to first array */
    int it2 = m-1; /* Iterator to second array */
    int it3 = m+n-1; /* Iterator to final array */

    while(it2>=0){
        if(it1>=0 && arr1[it1] > arr2[it2]) {
            arr1[it3--] = arr1[it1--];
        }else{
            arr1[it3--] = arr2[it2--];
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    vector<int> arr1(n+m,0),arr2(m);
    
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];

    merge_sorted_arr(arr1,n,arr2,m);

    cout<<"Resultant Array: ";
    for(const int it: arr1) cout<<it<<" ";
}