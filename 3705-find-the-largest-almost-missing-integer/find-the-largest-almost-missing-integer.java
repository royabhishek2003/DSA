class Solution {
    public int largestInteger(int[] nums, int k) {
        int n= nums.length;
        int maxele=-1;
        for(int ele: nums){
            maxele=Math.max(maxele,ele);
        }
        int freq[]= new int[51];
        for(int ele:nums) freq[ele]++;
        if(k==n){
            return maxele;
        }
        int maxelefreq1=-1;
        if(k==1){
           for(int i=n-1;i>=0;i--){
                if(freq[nums[i]]==1){
                    maxelefreq1= Math.max(maxelefreq1,nums[i]);
                }
           }
           return maxelefreq1;
        }
       

        if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
            return Math.max(nums[0],nums[n-1]);
        }else if(freq[nums[0]]==1){
            return nums[0];
        }else if(freq[nums[n-1]]==1) return nums[n-1];

        return -1;
       
    }
}