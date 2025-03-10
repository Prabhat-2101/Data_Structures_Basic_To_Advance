#include<bits/stdc++.h>
using namespace std;

void linear_search(vector<int> list,int key){
    int idx = -1;
    for(int it=0;it<list.size();it++){
        if(list.at(it)==key){
            idx = it;
            break;
        }
    }
    if(idx==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at index: "<<idx+1;
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
    cout<<"Key Element: ";
    cin>>Key;
    linear_search(list,Key);
    return 0;
}