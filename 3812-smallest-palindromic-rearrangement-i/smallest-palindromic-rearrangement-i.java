class Solution {
    String sort(String temp){
        int n= temp.length();
        char ch[]= new char[n];
        for(int i=0;i<n;i++){
            ch[i]=temp.charAt(i);
        }
        Arrays.sort(ch);
        return new String(ch);
    }
    String reverse(String temp){
        int n= temp.length();
        char ch[]= new char[n];
        for(int i=0;i<n;i++) ch[i]=temp.charAt(i);
        int i=0;
        int j=n-1;
        while(i<j){
            char t= ch[j];
            ch[j]=ch[i];
            ch[i]=t;
            i++;
            j--;
        }
        return new String(ch);
    }
    public String smallestPalindrome(String s) {
        int n= s.length();
        int size= n/2;
        String t=s.substring(0,size);
        String temp= sort(t);
        String ans=temp;
        if(n%2!=0){
            ans+=s.charAt(size);
        }
        t= reverse(temp);
        ans+=t;
        return ans;

    }
}