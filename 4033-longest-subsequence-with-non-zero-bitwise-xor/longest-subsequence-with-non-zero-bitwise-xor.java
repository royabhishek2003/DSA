class Solution {
    public int longestSubsequence(int[] nums) {
        int n= nums.length;;
        int xor=0;
        int zerocount=0;
        for(int ele: nums){
            xor = xor^ele;
            if(ele ==0)
            zerocount+=1;
        }
        // what if already all ement in the array is zero 
        if(xor==0) return  (zerocount!=n)?  n-1:0;
        return n;
    }
}