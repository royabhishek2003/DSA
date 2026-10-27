class Solution {
public:
    int n,m;
    int dp[101][101];
    bool vis[101][101];
    vector<int> column={0,-1,1};
    int solve(vector<vector<int>> &matrix, int i, int j){
        if(i==n-1){
            return matrix[i][j];
        }
        if(vis[i][j]) return dp[i][j];
        vis[i][j]=true;
        int minsum=INT_MAX;
        for(int &col:column ){
            if(i+1<n && j+col <m && j+col >=0)
            minsum= min(minsum, matrix[i][j] + solve(matrix,i+1,j+col));
        }
        return dp[i][j]= minsum;

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // n= matrix.size();
        // m= matrix[0].size();
        // int minsum=INT_MAX;
        // int row=0;
        // memset(dp,false,sizeof(vis));

        // for(int col=0;col<m;col++){
        //     minsum= min(minsum, solve(matrix,row,col));
        // }
        // return minsum;

        // Tabulation approach simpest 
        int n= matrix.size();
        vector<vector<int>> t(n,vector<int>(n,INT_MAX));
        // fill first row 
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            t[0][i]=matrix[0][i];
            if(n==1) ans=min(ans,t[0][i]);
        }
        // populate the result from 2nd row to the last row 
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                for(int &col: column){
                    if(j+col >=0 && j+col<n)
                    t[i][j]= min(t[i][j], matrix[i][j]+t[i-1][j+col]);
                    if(i==n-1) ans=min(ans,t[i][j]);
                }
            }
        }
        return ans;
    }
};