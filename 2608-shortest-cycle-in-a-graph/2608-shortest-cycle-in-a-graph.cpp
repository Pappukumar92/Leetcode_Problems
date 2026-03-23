class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MAX;
        for(int start = 0; start < n; start++){
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i = 0; i < adj[node].size(); i++){
                    int nei = adj[node][i];
                    if(dist[nei] == -1){
                        dist[nei] = dist[node] + 1;
                        parent[nei] = node;
                        q.push(nei);
                    }
                    else if(parent[node] != nei){
                        ans = min(ans, dist[node] + dist[nei] + 1);
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};