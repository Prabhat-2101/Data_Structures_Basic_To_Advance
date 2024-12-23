/*
PROBLEM LINKS:
    https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
    https://leetcode.com/problems/number-of-islands/
    https://www.naukri.com/code360/problems/find-number-of-islands_630512?leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c){
        visited[r][c] = true;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                
                int nrow = r + i;
                int ncol = c + j;
                
                if(nrow < row && nrow >= 0 && ncol < col && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol] == '1'){
                    visited[nrow][ncol] = true;
                    dfs(grid,visited,nrow,ncol);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        int res = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    res++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return res;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}