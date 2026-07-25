class Solution {
public:
    bool isreachable(unordered_map<int,set<int> >& adj, int u, int v,vector<bool> &visited){
        if(u==v) return true;
        visited[u]=true;
        for(auto &neighbour: adj[u]){
            if(!visited[neighbour]){
                if(isreachable(adj,neighbour,v,visited)) return true;
            }
        }

        return false;
    }
    void dfs(int curr, int parent, unordered_map<int,vector<int>> &adj,vector<int> &discover,vector<int>& low, vector<bool>& visited,int count, vector<vector<int>>& Bridges ){
        
       visited[curr]=1;
       discover[curr]=low[curr]=count;
       count++;
       for(auto &neighbour: adj[curr]){
        if(parent == neighbour) continue;
        if(visited[neighbour]){
            low[curr]= min(discover[neighbour],low[curr]);
        }else{
            dfs(neighbour,curr,adj,discover,low,visited,count,Bridges);
        }
        low[curr]= min(low[curr],low[neighbour]);
        if(low[neighbour] > discover[curr]){
            Bridges.push_back({curr,neighbour});
        }
       }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         
        // Brute Force check for each edge rempve it and caheck is it reachable
        // make graph 
        // unordered_map<int,set<int> > adj;
        // for(vector<int> &edge: connections){
        //     adj[edge[0]].insert(edge[1]);
        //     adj[edge[1]].insert(edge[0]);
        // }

        // vector<vector<int>> bridge;
        // for(vector<int> &edge: connections){
        //     int u= edge[0];
        //     int v= edge[1];
        //     adj[u].erase(v);
        //     adj[v].erase(u);
        //     vector<bool> visited(n,false);
        //     if(!isreachable(adj,u,v,visited)) {
        //         bridge.push_back({u,v});
        //     }
        //     adj[u].insert(v);
        //     adj[v].insert(u);
        // }

        // return bridge;


        // approach -2 using Tarjan's algorithm 
        
        unordered_map<int,vector<int>> adj;
        for(vector<int> &connection: connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        vector<int> discover(n); // discover time 
        vector<int> low(n);   // low time -> sabse kam discover time wale node pe pahuchna
        vector<bool> visited(n,0);
        int count=0;

        vector<vector<int>> Bridges;
        dfs(0,-1,adj,discover,low,visited,count,Bridges);

        return Bridges;
        

    }
};