// https://www.geeksforgeeks.org/problems/maximum-index3307/1?page=1&category=Arrays&difficulty=Medium,Hard&status=unsolved&sortBy=submissions
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        int mx = 0,size = arr.size();
        vector<int> min_(size,arr[0]);
        for(int i=1;i<size;i++){
            min_[i] = min(min_[i-1],arr[i]);
        }
        vector<int> max_(size,arr[size-1]);
        for(int i=size-2;i>=0;i--){
            max_[i] = max(max_[i+1],arr[i]);
        }
        int i=0,j=0;
        while(i<size && j<size){
            if(min_[i]<=max_[j]){
                mx = max(mx,j-i);
                j += 1;
            }else{
                i += 1;
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(arr);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}