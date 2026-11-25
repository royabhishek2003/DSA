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
        // vector<vector<int>> dp(n+1,vector<int>(totalsum+1,-1));
        if(totalsum %2 !=0) return false;
        // return solve(nums,0,0, dp);

        // using Tabulation 
        bool ans=false;
        vector<vector<int>> t(n+1,vector<int>(totalsum+1,0));
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=totalsum;sum++){
                if(sum > (totalsum/2)){
                    t[i][sum]=0;
                    continue;
                }
                if(sum == (totalsum/2)){
                    t[i][sum]=1;
                    continue;
                }
                int take=0;
                if(sum+ nums[i] <= totalsum){
                    take=  t[i+1][sum+nums[i]];
                }
                int not_take = t[i+1][sum];
                t[i][sum]= take || not_take;
            }
        }

        return t[0][0];

    }
};