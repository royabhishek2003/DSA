class Solution {
    public int longestBalanced(int[] nums) {
        int n= nums.length;
       
        int ans =0;
        for(int i=0;i<n;i++){
            HashSet<Integer> odd= new HashSet();
            HashSet<Integer> even= new HashSet();
            for(int j=i;j<n;j++){
                if(nums[j]%2!=0){
                    odd.add(nums[j]);
                }else even.add(nums[j]);
                if(odd.size() == even.size()){
                    ans= Math.max(ans,j-i+1);
                }
            }
        }
        return ans;

    }
}