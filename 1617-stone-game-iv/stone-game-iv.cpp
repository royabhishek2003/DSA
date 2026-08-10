class Solution {
public:
    int dp[100001];
    vector<int> perfectsqarelessthenN(int n){
        vector<int> result;
        for (int i = 1; i * i <= n; i++) {
            result.push_back(i * i);
        }
        return result;
    }
    bool solve(int n, int turn){
        if(n<0){
            return false;
        }
        if(dp[n]!=-1) return dp[n];
        vector<int> findsqrt= perfectsqarelessthenN(n);
        int size = findsqrt.size();
        for(int i=0; i<size; i++){
            if(turn ==0){
               if(!solve(n-findsqrt[i],1))  return dp[n]= true;
            }
            else{
                if(!solve(n-findsqrt[i],0)) return dp[n]= true;
            }
        }
        return dp[n]= false;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};