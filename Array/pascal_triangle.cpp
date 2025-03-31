#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
int mod = 1e9+7;
    vector<long long> nthRowOfPascalTriangle(int n) {
        vector<vector<ll>>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }
        return dp[n-1];
    }
};

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}