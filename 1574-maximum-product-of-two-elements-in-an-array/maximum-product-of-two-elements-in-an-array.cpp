class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max=-1;
        int secondmax= -1;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > max){
                secondmax= max;
                max= nums[i];
            }else if(nums[i] > secondmax){
                secondmax= nums[i];
            }
        }

        return (secondmax-1)*(max-1);
    }
};