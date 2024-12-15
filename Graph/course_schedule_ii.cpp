#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> findOrder(int size, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(size);
        vector<int> indegree(size,0);
        for(const auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]] += 1;
        }
        vector<int> order;
        int count = 0;
        queue<int> q; 
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front(); q.pop();
            count += 1;
            order.push_back(top);
            for(int it: adj[top]){
                indegree[it] -= 1;
                if(indegree[it]==0) q.push(it);
            }
        }
        return count==size?order:vector<int>();
    }
};


int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
        cout << "~" << "\n";
    }
    return 0;
}