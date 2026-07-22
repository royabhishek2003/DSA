class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n= colors.length();
        // making a adjacency list (directed graph)
        unordered_map<int,vector<int>> adj;
        vector<int>indegree(n,0);
        for(vector<int> &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            dp[i][colors[i]-'a']=1;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        int ans=-1;
        int visited=0;
        while(!q.empty()){
            int curr= q.front();
            visited++;
            q.pop();
            for(int i=0;i<26;i++){
                ans= max(ans, dp[curr][i]);
            }
            for(auto &neighbour: adj[curr]){
                for(int i=0;i<26;i++){
                    if(i==colors[neighbour]-'a'){
                        dp[neighbour][i]= max(dp[neighbour][i], dp[curr][i]+1);
                    }
                    else dp[neighbour][i]= max(dp[neighbour][i], dp[curr][i]);
                }
                indegree[neighbour] --;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }

        if(n!=visited) return -1;
        return ans;




    

    }
};