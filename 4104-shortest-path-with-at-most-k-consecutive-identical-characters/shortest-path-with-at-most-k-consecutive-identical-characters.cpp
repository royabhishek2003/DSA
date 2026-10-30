class Solution {
public:
    typedef tuple<int,int,int> t;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // make directed graph 
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        priority_queue<t,vector<t>, greater<t> > pq;
        pq.push({0,0,1}); // {dis,node,cosecutivecount}
        vector<vector<int>> result(n,vector<int>(k+1,INT_MAX));
        result[0][1]=0;
        while(!pq.empty()){
            auto [dis,curr,count]= pq.top();
            pq.pop();
            if(curr == n-1){
                return dis;
            }
            for(auto &p: adj[curr]){
                int neighnode= p.first;
                int d=p.second;
                int newcount = (labels[neighnode]==labels[curr])? count+1 : 1;
                if(newcount > k) continue;
                if(dis+d < result[neighnode][newcount]){
                    result[neighnode][newcount]=dis+d;
                    pq.push({dis+d, neighnode, newcount});
                }
            }
        }

       int minpath= *(min_element(result[n-1].begin(), result[n-1].end()));
       if(minpath == INT_MAX) return -1;
       return minpath;


    }
};