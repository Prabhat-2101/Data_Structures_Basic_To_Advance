#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& preq) {
	    vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(const auto edge: preq){
            adj[edge.first].push_back(edge.second);
            indegree[edge.second] += 1;
        }
        int count = 0;
        queue<int> q; 
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int top = q.front(); q.pop();
            count += 1;
            for(int it: adj[top]){
                indegree[it] -= 1;
                if(indegree[it]==0) q.push(it);
            }
        }
        return count == n;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
        cout << "~" << "\n";
    }
	return 0;
}