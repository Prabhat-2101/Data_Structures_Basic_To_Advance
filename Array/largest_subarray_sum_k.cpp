#include<bits/stdc++.h>
using namespace std;

int largest_subarray(vector<int> &nums,int n,int k){
    int max_len = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum == k)
                max_len = max(max_len,j-i+1);
        }
    }
    return max_len;
}

int largest_subarray_optimised(vector<int> &nums,int n,int k){
    int max_len = 0,sum=0;
    unordered_map<long long,int> umap;
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum==k){
            max_len = i+1;
        }
        if(umap.find(sum) == umap.end())
            umap[sum] = i;
        if(umap.find(sum-k) != umap.end())
            max_len = max(max_len,i-umap[sum-k]);
    }
    return max_len;
}

int main(){
    int N=6,K=15;
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    cout<<largest_subarray_optimised(nums,N,K)<<endl;
    return 0;
}