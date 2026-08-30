class Solution {
    public int minimumDeletions(int[] nums) {
        
        int minidx=0;
        int maxidx =0;
        int minele=nums[0];
        int maxele=nums[0];
        int n= nums.length;
        if(n==1 ) return 1;
        else if(n==2) return 2;
        for(int i=0;i<n;i++){
            if(nums[i] > maxele){
                maxele=nums[i];
                maxidx=i;
            }
            if(nums[i] < minele){
                minele = nums[i];
                minidx = i;
            }
        }
        int front = Math.max(minidx, maxidx) + 1;
        int back = Math.max(n - minidx, n - maxidx);
        int mixed = Math.min(minidx + 1, n - minidx)
          + Math.min(maxidx + 1, n - maxidx);

return Math.min(front, Math.min(back, mixed));



    }
}