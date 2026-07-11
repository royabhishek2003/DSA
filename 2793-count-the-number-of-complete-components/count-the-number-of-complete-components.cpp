class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>> &adj,vector<bool> &visited, int &edge, int &node ){
        visited[u]=true;
        node++;
        edge += adj[u].size();
        for(int &v: adj[u]){
            if(!visited[v]) dfs(v,adj,visited,edge,node);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
       unordered_map<int,vector<int>> adj;
       for(vector<int> &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
       }

       vector<bool> visited(n);
       int count=0;
       for(int i=0;i<n;i++){
            if(!visited[i]){
                int edge=0;
                int node=0;
                dfs(i,adj,visited,edge,node);
                edge= edge/2;
                if(edge == node*(node-1)/2) count++;
            }
       }

       return count;
    }
};