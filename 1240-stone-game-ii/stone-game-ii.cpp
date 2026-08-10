class Solution {
public:
    int n;
    int dp[101][49][2];
    int solve(int i, auto &piles,int m, int turn){

        if(i>=n){
            return 0;
        }
        if(dp[i][m][turn] != -1) return dp[i][m][turn];
        int result = (turn ==0)?0:INT_MAX;
        int taken=0;
        for(int x=1;x <= 2*m && i+x <= n; x++){
            taken += piles[x+i-1];
            if(turn ==0){ // alice ki turn hai
                result= max(result,taken+ solve(i+x,piles,max(x,m),1) );
            }else{ // bob ki bari hai 
                result = min(result,solve(i+x,piles,max(x,m),0));
            }
        }
        return  dp[i][m][turn]= result;
    }
    int stoneGameII(vector<int>& piles) {
        n= piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,1,0);
    }
};