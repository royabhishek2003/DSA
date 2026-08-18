class Solution {
    public int largestInteger(int[] nums, int k) {
        int n= nums.length;
        int temp[]= new int[n];
        for(int i=0;i<n;i++){
            temp[i]=nums[i];
        }
        Arrays.sort(temp);
        int maxele=-1;
        for(int ele: nums){
            maxele=Math.max(maxele,ele);
        }
        int freq[]= new int[51];
        for(int ele:nums) freq[ele]++;
        if(k==n){
            return maxele;
        }
        if(k==1){
           for(int i=n-1;i>=0;i--){
            if(freq[temp[i]]==1) return temp[i];
           }
        }
       

        if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
            return Math.max(nums[0],nums[n-1]);
        }else if(freq[nums[0]]==1){
            return nums[0];
        }else if(freq[nums[n-1]]==1) return nums[n-1];

        return -1;
       
    }
}