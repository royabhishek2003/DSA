class Solution {
public:
    int maxlengthcycle = -1;
    void dfs(int u, auto &visited, auto &inrecursion,auto &count,auto &edges){
        int v= edges[u];
        if(v == -1) return;
        visited[u]=true;
        inrecursion[u]=true;
        
        if(visited[v] && inrecursion[v]){
            maxlengthcycle= max(maxlengthcycle,count[u]-count[v]+1);
        }
        count[v]=count[u] + 1;
        if(!visited[v])
        dfs(v,visited,inrecursion,count,edges);
        inrecursion[u]=false;
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<bool> visited(n,false);
        vector<bool> inrecursion(n,false);
        vector<int> count(n,1);

        for(int i=0;i<n;i++){
            if(edges[i]!=-1 && !visited[i]){
                dfs(i,visited,inrecursion,count,edges);
            }
        }
        return maxlengthcycle;
    }
};