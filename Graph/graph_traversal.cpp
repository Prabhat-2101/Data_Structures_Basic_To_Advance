#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>

vvi depthFirstSearch(int V, int E, vvi &edges){
    vvi res;
    vvi graph(V,vector<int>(V,0));
    for(const auto it: edges){
        int st = it[0],end = it[1];
        graph[st][end] = 1;
        graph[end][st] = 1;
    }
    vector<bool> visited(V,false);
    auto dfs = [&](int idx,vector<int>& temp){
        stack<int> st; st.push(idx);
        visited[idx] = true;
        while(!st.empty()){
            int top = st.top(); st.pop();
            temp.push_back(top);
            for(int i=0;i<V;i++){
                if(graph[top][i] && !visited[i]){
                    st.push(i);
                    visited[i] = true;
                } 
            }
        }
    };
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            vector<int> temp;
            dfs(i,temp);
            res.push_back(temp);
        }
    }
    return res;
}

vector<int> bfs(int n, vector<set<int>> &adj){
    int nodes = adj.size();
    vector<int> res;
    vector<bool> visited(nodes,false);
    queue<int> q; q.push(0);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        res.push_back(curr);
        visited[curr] = true;
        for(const int it: adj[curr]){
            if(!visited[it]) {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    return res;
}

int main(){
    int nodes;cin>>nodes;
    int edge; cin>>edge;
    vector<set<int>> adj(nodes);
    for(int i=0;i<edge;i++){
        int start,end;cin>>start>>end;
        adj[start].insert(end);
    }
    vector<int> bfs_traversal = bfs(nodes,adj);
    for(const int it: bfs_traversal) cout<<it<<" ";
    cout<<endl;
    return 0;
}