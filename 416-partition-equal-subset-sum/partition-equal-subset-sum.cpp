class Solution {
public:
    int totalsum=0;;
    int n;
    bool solve(vector<int> &nums, int i, int sum, vector<vector<int>> &dp){
        if(i>=n || sum > (totalsum/2)){
            return  false;
        }
        if(sum == (totalsum/2)) return dp[i][sum]= true;
        if(dp[i][sum] !=-1) return dp[i][sum];
        bool take= solve(nums,i+1,sum+nums[i], dp);
        bool not_take= solve(nums, i+1, sum, dp);
        if(take || not_take) return dp[i][sum]= true;
        return dp[i][sum]= false;
    }
    bool canPartition(vector<int>& nums) {
        n= nums.size();
        for(int &ele: nums){
            totalsum+=ele;
        }
        vector<vector<int>> dp(n+1,vector<int>(totalsum+1,-1));
        if(totalsum %2 !=0) return false;
        return solve(nums,0,0, dp);
    }
};