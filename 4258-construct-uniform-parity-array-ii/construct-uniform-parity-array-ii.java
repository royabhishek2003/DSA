class Solution {
    public boolean uniformArray(int[] nums1) {
    // agar ek bhi element odd ho gya toh sre element odd ban sakta hai bas wo element odd wale se bada ho 
    // sbase chota odd ko pakdo aur koi even us odd se bi chota ho toh impossible hai otherwise its possible 

    int oddmin=Integer.MAX_VALUE;
    for(int ele: nums1){
        if(ele % 2!=0 ) oddmin= Math.min(ele,oddmin);
    }

    for(int ele: nums1){
        if(ele % 2==0 && oddmin != Integer.MAX_VALUE && ele <= oddmin) return false;
    }
    return true;
    }
}