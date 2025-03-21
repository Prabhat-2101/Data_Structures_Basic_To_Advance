#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int size = adj.size();
        vector<int> res;
        vector<int> indegree(size,0);
        for(const auto list: adj){
            for(int idx: list){
                indegree[idx] += 1;
            }
        }
        queue<int> q;
        for(int i=0;i<size;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int top = q.front(); q.pop();
            res.push_back(top);
            for(int it: adj[top]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return res;
    }
};

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}