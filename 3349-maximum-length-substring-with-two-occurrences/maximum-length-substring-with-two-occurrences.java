class Solution {
    public int maximumLengthSubstring(String s) {
        
        int maxfreq=0;
        char maxfreqele=' ';
        int n= s.length();
        Map<Character,Integer> mp= new HashMap<>();
        int result=0;
        int i=0;
        int j=0;
        while(j<n){
            if(mp.containsKey(s.charAt(j))==false){
                mp.put(s.charAt(j),1);
            }
            else mp.put(s.charAt(j),mp.get(s.charAt(j))+1);
            if(mp.get(s.charAt(j)) > maxfreq){
                maxfreq=mp.get(s.charAt(j));
                maxfreqele=s.charAt(j);
            }

            while(maxfreq > 2){
                mp.put(s.charAt(i),mp.get(s.charAt(i))-1);
                if(maxfreqele==s.charAt(i)){
                    maxfreq = mp.get(s.charAt(i));
                }
                i++;
            }

            result= Math.max(result,j-i+1);
            j++;
        }

        return result;
    }
}