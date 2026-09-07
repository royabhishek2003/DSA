class Solution {
    int[] dp;
    int  mod = 1000000007;
    int solve(int n, int[] prev){
        if(n==-1 || n==0){
            return 1;
        }
        if(dp[n] != -2) return dp[n];
        int  currans= (2*solve(n-1,prev)) % mod ;
        int duplicates=0;
        if(prev[n-1]!=-1){
            duplicates= solve(prev[n-1], prev);
            duplicates = duplicates%mod;
        }
       return  dp[n]= (currans - duplicates +mod)%mod;
    }
    public int distinctSubseqII(String s) {
        // Optimal Soution using last seen technique 
        // here we just need solve(n) = 2 * solve(n-1) 
        // and for ensuring the duplicates we just need to find the firstt time we have encountered the character and at that time how many subsequence is there so we just need to substract that much subsequence from current answer 
        // maintain the prev array 

        int n= s.length();
        int []prev= new int[n];
        dp= new int[n+1];
        Arrays.fill(prev, -1);
        Arrays.fill(dp,-2);
       Map<Character,ArrayList<Integer>> mp= new HashMap<>();
        for(int i=0;i<n;i++){
            Character ch= s.charAt(i);
            if(!mp.containsKey(ch)){
                mp.put(ch,new ArrayList<>());
            }
            ArrayList<Integer> l= mp.get(ch);
            l.add(i);
            if(l.size() > 1){
                prev[i]= l.get(l.size() -2);
            }
        }

        return (solve(n,prev)+mod -1)%mod;
        
    }
}