class Solution {
public:
    // bool solve (int i, int j, auto &nums, int p1, int p2,int count){
    //     if(i>j){
    //         return p1>=p2;
    //     }
    //     if(count%2==0){ // p1's turn 
    //         bool takefirst= solve(i+1,j,nums,p1+nums[i],p2,count+1);
    //         bool takelast= solve(i,j-1,nums,p1+nums[j],p2,count+1);

    //         return takefirst || takelast;

    //     }else{  // p2's turn
    //         bool takefirst= solve(i+1,j,nums,p1,p2+nums[i],count+1);
    //         bool takelast= solve(i,j-1,nums,p1,p2+nums[j],count+1);

    //         return takefirst && takelast; // plaer 2 choose their optimally move 
    //     }
        
    // }

    int dp[20][20];

    int solve(int i, int j, auto &nums, auto &dp){
        if(i>= nums.size() || j<0) return 0;
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int takefirst= nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int takelast= nums[j] + min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));

        return dp[i][j]= max(takefirst,takelast);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        // int count=0;
        // int n= nums.size();
        // return solve(0,n-1,nums,0,0,0);

        int n= nums.size();
        memset(dp,-1,sizeof(dp));
        int total_sum=0;
        for(int &ele: nums) total_sum += ele;


        int player1result= solve(0,n-1,nums,dp);
        if(total_sum - player1result > player1result) return false;
        return true;
    }
};