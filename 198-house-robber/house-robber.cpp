class Solution {
public:
    int helper(int i,vector<int> &nums, vector<int> &dp){
            if(i>=nums.size()) return 0;
            if(dp[i]!=-1) return dp[i];
        int steal= nums[i]+ helper(i+2,nums, dp) ;
        int leave= helper(i+1, nums, dp);
        return dp[i]= max(steal, leave);
    }

    int rob(vector<int>& nums) {
        // same as coin row problem 

        //  By recurion + tabulation
        int n= nums.size(); 
        vector<int> dp(n, -1);
        return helper(0,nums, dp);

        // by tabulation 
        // int n= nums.size();
        // if(n==1) return nums[0];
        // if(n==2) return max(nums[0], nums[1]);
        // vector<int> result(n);
        // result[0]=nums[0];
        // result[1]= max(nums[1],nums[0]);
        // for(int i=2;i<n;i++){
        //     result[i]= max(result[i-1], nums[i]+result[i-2]);
        // }
        // return result[n-1];
    }
};