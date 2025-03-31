#include<bits/stdc++.h>
using namespace std;

vector<int> first_neg_in_subarray(vector<int> &nums,int n,int k){
    vector<int> res;
    for(int start=0;start<=n-k;start++){
        int neg = 0;
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                neg = nums[i];
                break;
            }
        }
        res.push_back(neg);
    }
    return res;
}

vector<int> first_neg_in_subarray_optimised(vector<int> &nums,int n,int k){
    vector<int> res;
    vector<pair<int,int>> negative;
    for(int i=0;i<n;i++){
        if(nums[i]<0)
            negative.push_back(make_pair(nums[i],i));
    }
    int counter=0;
    for(int i=0;i<=n-k;i++){
        if(counter==negative.size())
            res.push_back(0);
        else{
            lli idx = negative[counter].second;
            if(i+k > idx)
                res.push_back(negative[counter].first);
            else
                res.push_back(0);
            if(nums[i] == negative[counter].first)
                counter += 1;
        }
    }
    return res;
}

int main(){
    int N=5,K=2;
    vector<int> nums = {-8, 2, 3, -6, 10};
    vector<int> res = first_neg_in_subarray_optimised(nums,N,K);
    for(const int &ele: res)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}