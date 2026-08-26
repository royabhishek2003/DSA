class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int size=101;
        String ans="";
        int i=0;
        int j=0;
        int n= s.length();
        int currk=0;
        while(j<n){
            if(s.charAt(j)=='1'){
                currk++;
            }
            while(currk > k){
                if(s.charAt(i)=='1') currk--;
                i++;
            }
            if(currk == k){
                while (s.charAt(i) == '0') {
                    i++;
                }
                
                String temp= s.substring(i,j+1);
                if(j-i+1 < size){
                    ans= temp;
                    size= j-i+1;
                }
                else if(j-i+1 == size ){
                    if(ans.compareTo(temp) > 0) ans=temp;
                }
            }
            j++;
        }

        return ans;
    }
}