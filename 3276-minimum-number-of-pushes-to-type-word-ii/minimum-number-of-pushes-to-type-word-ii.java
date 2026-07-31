class Solution {
    public int minimumPushes(String word) {
       ArrayList<Integer> freq= new ArrayList<>(Collections.nCopies(26,0));
       for(char ch: word.toCharArray()) freq.set(ch -'a' , freq.get(ch-'a')+1);

       Collections.sort(freq);
       Collections.reverse(freq);
       int key=2;
       int ans=0;
       int round=1;
       for(int i=0;i<26;i++){
        if(freq.get(i)==0) return ans;
        if(key>9){
            key=2;
            round+=1;
        }
        ans += round*freq.get(i);
        key++;
       }
       return ans;
    }
}