/*
PROBLEM LINKS:
    https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
    https://www.geeksforgeeks.org/problems/number-of-provinces/1
    https://www.naukri.com/code360/problems/find-the-number-of-states_1377943
    https://leetcode.com/problems/number-of-provinces/description/
*/

#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Solution {
    public:
    void dfs(int vertex,vector<vector<int>>&ans,vector<vector<int>>&adj,int cnt,vector<int>&vis){
        ans[cnt].push_back(vertex);
      
        vis[vertex]=1;
      
        for(int child:adj[vertex]){
            if(vis[child]) continue;
            dfs(child,ans,adj,cnt,vis);
        }
      
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        vector<vector<int>>adj(v);
        vector<int>vis(v,0);
        for(int i=0;i<edges.size();i++){
            int v1=edges[i][0];
            int v2=edges[i][1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        vector<vector<int>>ans(v);
        int cnt=-1;
        for(int i=0;i<v;i++){
            if(vis[i]) continue;
            cnt++;
            
            dfs(i,ans,adj,cnt,vis);
            sort(ans[cnt].begin(),ans[cnt].end());
         }
         ans.resize(cnt+1);
         return ans;
    }
};
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}