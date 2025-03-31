#include <iostream>
using namespace std;

bool sorted(int arr[],int i,int n){
    if(i>=n-1)
        return true;
    if(arr[i]<=arr[i+1] && sorted(arr,i+1,n))
        return true;
    return false;
}

int main(){
    int N;cin>>N;
    int arr[N]; 
    for(int i=0;i<N;i++)
        cin>>arr[i];
    if(sorted(arr,0,N))
        cout<<"sorted";
    else
        cout<<"Not sorted";
    return 0;
}