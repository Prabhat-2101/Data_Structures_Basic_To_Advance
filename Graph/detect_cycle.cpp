#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indegree(V,0);
        int count = 0;
        for(const auto list: adj){
            for(const int it: list) indegree[it] += 1;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front(); q.pop();
            count += 1;
            for(const int it: adj[top]) {
                indegree[it] -= 1;
                if(indegree[it]==0) q.push(it);
            }
        }
        return count != V;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"<< "\n";
    }

    return 0;
}