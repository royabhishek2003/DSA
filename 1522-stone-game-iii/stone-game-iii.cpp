class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int i, auto &stonevalue,int turn){
        if(i>=n) return 0;
        if(dp[i][turn] !=-1) return dp[i][turn];
        int result = (turn ==0)? INT_MIN: INT_MAX;
        int taken=0;
        for(int x=i;x<=i+2 && x<n;x++){
            taken += stonevalue[x];
            if(turn ==0){  // alice turn
                result = max(result, taken + solve(x+1,stonevalue,1));
            }else{
                result = min(result, solve(x+1,stonevalue,0));
            }
        }
        return dp[i][turn]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int totalsum=0;
        n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        for(int ele: stoneValue) totalsum+=ele;
        int alicescore= solve(0,stoneValue,0);
        if(alicescore > totalsum-alicescore){
            return "Alice";
        }else if(alicescore < totalsum-alicescore){
            return "Bob";
        }else  return "Tie";

    }
};