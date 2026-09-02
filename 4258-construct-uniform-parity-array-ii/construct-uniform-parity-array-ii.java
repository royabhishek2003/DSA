class Solution {
    public boolean uniformArray(int[] nums1) {
        
        Arrays.sort(nums1);

        boolean iseven= true;
        boolean isodd= true;
        int evencount=0;
        int oddcount=0;
        for(int ele: nums1){
            if(ele %2 ==0) {
                evencount+=1;
                continue;
            }
            if(oddcount ==0) {
                iseven=false;
                break;
            }
            if(ele %2 ==0) evencount+=1;
                else oddcount+=1;
        }
        if(iseven) return true;
        oddcount=0;
        evencount=0;
        for(int ele: nums1){
            if(ele % 2 !=0){
                oddcount+=1;
                continue;
            }
            if(oddcount ==0) {
                isodd=false;
                break;
            }
            if(ele %2 ==0) evencount+=1;
                else oddcount+=1;
        }
        if(isodd) return true;

        return false;

    }
}