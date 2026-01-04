class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> visited;
        for(const auto& edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int num = 0;
        for(int node=0; node<n; node++) {
            if(visited.count(node)==0) {
                dfs(node, adj, visited);
                num++;
            }
        }
        return num;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);
        for(int neighbor: adj[node]) {
            if(visited.count(neighbor)==0) {
                dfs(neighbor, adj, visited);
            }
        }
    }
};
