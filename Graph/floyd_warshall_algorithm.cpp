#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(mat[i][j]==-1) mat[i][j] = 1e9;
                if(i==j) mat[i][j] = 0;
            }
        }
        for(int mid=0;mid<n;mid++){
            for(int st=0;st<n;st++){
                for(int end=0;end<n;end++){
                    mat[st][end] = min(mat[st][end],mat[st][mid]+mat[mid][end]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) if(mat[i][j]==1e9) mat[i][j] = -1;
        }
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~"<< "\n";
    }
    return 0;
}