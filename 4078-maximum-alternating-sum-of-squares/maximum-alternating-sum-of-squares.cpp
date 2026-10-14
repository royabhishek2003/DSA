class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        // for(int &ele: nums){
        //     if(ele<0) ele*=-1; 
        // }
        auto mycomp = [&](int &a, int &b){
            return abs(a)<abs(b);
        };
        sort(nums.begin(),nums.end(), mycomp);
        long long ans=0;
        int i=0;
        int j= n-1;
        if(n%2 !=0){
            ans+=nums[j]*nums[j];
            j-=1;
        }
        while(i<j){
            ans+= nums[j]*nums[j] - nums[i]*nums[i];
            i+=1;
            j-=1;
        }
        return ans;
    }
};