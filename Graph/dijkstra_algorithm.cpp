#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int size = adj.size();
        vector<int> dist(size,INT_MAX);
        dist[src] = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(src);
        while(!pq.empty()){
            int node = pq.top(); pq.pop();
            for(const auto list: adj[node]){
                int pos = list.first, curr_dist = list.second;
                if(curr_dist + dist[node] < dist[pos]){
                    dist[pos] = curr_dist + dist[node];
                    pq.push(pos);
                }
            }
        }
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}