class Solution {
    public long countSubstrings(String s, char c) {
        // linear solution jab bhi naya c dekgo wo khud ek substring hai toh count+1 toh hoga aur pehle jitne c dekh chuke hinge utna aur count me add hoga kyuki uske sath bhi substring bana sakte hai 

        // long prevcount=0;
        // long count=0;
        // for(char ch: s.toCharArray()){
        //     if(ch==c){
        //         count+=1;
        //         count+=prevcount;
        //         prevcount+=1;
        //     }
        // }
        // return count;

        // 2nd approach is i have n (c) then it can be arranged in n(n+1)/2 ways 

        int count=0;
        for(char ch: s.toCharArray()){
            if(ch==c) count++;
        }
        return (long)count*(count+1)/2;
    }
}