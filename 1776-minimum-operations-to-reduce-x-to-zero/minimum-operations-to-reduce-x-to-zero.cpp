class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int i=0;
        int j=0;
        int maxlength=-1;
        int subarraysum=0;
        while(j<n){
            subarraysum+=nums[j];
            while(sum- subarraysum <x && i<n){
                subarraysum-=nums[i];
                i++;
            }
            if(sum - subarraysum == x){
                maxlength= max(maxlength,(j-i+1));
            }
            j++;
        }
        if(maxlength==-1) return -1;
        return n-maxlength;
    }
};