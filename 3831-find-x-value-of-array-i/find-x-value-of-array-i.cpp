class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // we need to find the number of subrray whose product%k is x where x is i;
        // Brute Force calculate all the subarray product and its remainder and make count++ for each remainder
        // Tc->o(n^3) 

        // we can use memoization while calculating product(i,j)
        // average Tc->O(n^2)

        // optimized
        // number of subarray ending at i having product remainder 0,1,2,--k-1
        vector<long long> result(k,0);
        vector<long long> prevCount(k,0);
        int n= nums.size();
        for(int i=0;i<n;i++){
            vector<long long> currCount(k,0);
            int currrem= nums[i]%k;
            currCount[currrem]+=1;

            for(int oldrem=0;oldrem<=k-1;oldrem++){
                long long newrem= (((long long)oldrem*nums[i])%k)%k;
                currCount[newrem] += prevCount[oldrem]; // most important observation 
            }
            prevCount= currCount;
            for(int x=0;x<=k-1;x++){
                result[x] += currCount[x];
            }
        } 

        return result;
    }

};