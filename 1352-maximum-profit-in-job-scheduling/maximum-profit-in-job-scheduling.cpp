class Solution {
public:
    int n;
    int dp[50001];
    int solve(auto& jobs, int i,auto& start){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int nxt = lower_bound(start.begin(),start.end(),jobs[i][1]) - start.begin();

        int take= jobs[i][2] + solve(jobs,nxt,start);
        int not_take= solve(jobs,i+1,start);

        return dp[i]= max(take,not_take);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        n= startTime.size();
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>start;
        for(vector<int> &vec: jobs){
            start.push_back(vec[0]);
        }
        memset(dp,-1,sizeof(dp));
        return solve(jobs,0,start);
    }
};