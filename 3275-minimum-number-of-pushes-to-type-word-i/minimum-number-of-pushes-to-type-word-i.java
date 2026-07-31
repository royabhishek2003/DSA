class Solution {
    public int minimumPushes(String word) {
        int ans=0;
        HashMap<Integer,Integer> mp= new HashMap<>();
        int count=2;
        for(char ch: word.toCharArray()){
            if(count>9) count=2;
            if(!mp.containsKey(count)) mp.put(count,1);
            else mp.put(count,mp.get(count)+1);
            ans += mp.get(count);
            count+=1;
        }
        return ans;
    }
}