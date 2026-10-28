class Solution {
public:
    int n;
    int dp[201][20101];
    bool vis[201][20101];
    int solve(vector<vector<int>> & triangle, int i, int j){
        if(i==n-1){
            return triangle[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        vis[i][j]=true;
        int minsum= INT_MAX;
        if(i+1<n){
            minsum = min(minsum, triangle[i][j] + solve(triangle,i+1,j));
            minsum = min(minsum, triangle[i][j] + solve(triangle,i+1,j+1));
        }
        return dp[i][j]= minsum;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n= triangle.size();
        // memset(vis,false,sizeof(vis));
        // return solve(triangle,0,0);

        // using Tabulation approach 
        vector<vector<int>> t;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<triangle[i].size();j++){
                temp.push_back(INT_MAX);
            }
            t.push_back(temp);
        }
        t[0][0]=triangle[0][0];
        if(n==1) return t[0][0];
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                if(t[i-1].size()>j) t[i][j]= min(t[i][j], triangle[i][j]+ t[i-1][j]);
                if(j-1>=0) t[i][j]= min(t[i][j], triangle[i][j]+ t[i-1][j-1]);
                if(i==n-1){
                    ans= min(ans,t[i][j]);
                }
            }
        }
        return ans;

    }
};