class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(auto &scores, auto &ages, int i, int prev){
        if(i>=n) return 0;
        int take=0;
        if( prev !=-1 && dp[i][prev] != -1) return dp[i][prev];
        if(prev == -1 || !(ages[prev] < ages[i] && scores[prev]>scores[i])){
            take = scores[i] + solve(scores,ages,i+1,i);
        }
        int not_take= solve(scores,ages,i+1,prev);

        if(prev!=-1)
        return dp[i][prev]= max(take, not_take) ;
        else return max(take,not_take)  ;

    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        n= scores.size();
        vector<pair<int,int>> vec;
        
        for(int i=0;i<n;i++){
            vec.push_back({ages[i],scores[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            scores[i]=vec[i].second;
            ages[i]=vec[i].first;
        }
        memset(dp,-1,sizeof(dp));
        return solve(scores,ages,0,-1);
    }
};