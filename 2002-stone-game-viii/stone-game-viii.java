class Solution {
    int n;
    int []prefixsum;
    int []dp;
    int solve(int i){
        if(i==n-1){
            return prefixsum[n-1];
        }
        if(dp[i]!=-1) return dp[i];
        int take = prefixsum[i] - solve(i+1);  // alicesore - calculateforbob -(alice- calculateforbob) =>alice + alice -(bob + bob+...)

        int not_take= solve(i+1);
        return dp[i]= Math.max(take,not_take);
    }
    public int stoneGameVIII(int[] stones) {
        // n= stones.length;
        // prefixsum= new int[n];
        // dp= new int[n+1];
        // for(int i=0;i<=n;i++) dp[i]=-1;
        // prefixsum[0]=stones[0];

        // for(int i=1;i<n;i++){
        //     prefixsum[i] += prefixsum[i-1]+stones[i];
        // }

        // return solve(1);  // return the diffference of alicescore - bob score 


        // Bottom up approach cause top down still gives TLE 
        int n= stones.length;
        int [] prefixsum= new int[n];
        prefixsum[0]=stones[0];
        for(int i=1;i<n;i++){
            prefixsum[i] = prefixsum[i-1] + stones[i];
        }

        int []t= new int[n+1];
        t[n-1]=prefixsum[n-1];
        for(int i=n-2;i>=1;i--){
            int take= prefixsum[i] - t[i+1];
            int not_take= t[i+1];
            t[i]= Math.max(take,not_take);
        }
        return t[1];
        

    }
}