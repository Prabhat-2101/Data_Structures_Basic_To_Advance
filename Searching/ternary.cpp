#include<bits/stdc++.h>
using namespace std;

int ternary_search(vector<int> list,int i,int j,int key){
    if(i >= j)
        return -1;
    int mid1 = i + (j-i)/3;
    int mid2 = r - (j-i)/3;
    if(list[mid1] == key)
        return mid1;
    else if(list[mid2] == key)
        return mid2;
    else if(list[mid1] > key)
        ternary_search(list,i,mid1-1,key);
    else if(list[mid2] < key)
        ternary_search(list,mid2+1,j,key);
    else
        ternary_search(list,mid1+1,mid2-1,key);
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
    int idx = ternary_search(list,0,N-1,Key);
    if(idx == -1)
        cout<<"Element not found";
    else
        cout<<"After sorting Element found at index: "<<idx+1;
    return 0;
}