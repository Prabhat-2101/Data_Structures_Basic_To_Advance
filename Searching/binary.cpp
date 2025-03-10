#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> list,int i,int j,int key){
    if(i >= j)
        return -1;
    int mid = (i+j)/2;
    if(list[mid] == key)
        return mid;
    else if(list[mid] < key)
        binary_search(list,mid+1,j,key);
    else
        binary_search(list,i,mid-1,key);
    return -1;
}

int main(){
    int N,Key;
    cout<<"Size of List: ";
    cin>>N;
    vector<int> list;
    cout<<"Enter elements: ";
    for(int it=0;it<N;it++){
        int val;
        cin>>val;
        list.push_back(val);
    }
    sort(list.begin(),list.end());
    cout<<"Key Element: ";
    cin>>Key;
    int idx = binary_search(list,0,N-1,Key);
    if(idx == -1)
        cout<<"Element not found";
    else
        cout<<"After sorting Element found at index: "<<idx+1;
    return 0;
}