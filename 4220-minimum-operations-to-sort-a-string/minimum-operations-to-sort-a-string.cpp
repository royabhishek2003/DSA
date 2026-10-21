class Solution {
public:
    int minOperations(string s) {
        int n= s.length();
        if(is_sorted(s.begin(), s.end())) return 0;
        char minchar= *min_element(s.begin(),s.end());
        char maxchar= *max_element(s.begin(),s.end());
        if(s[0]==maxchar && s[n-1]==minchar && n==2) return -1;
        if(s[0]==minchar || s[n-1]==maxchar) return 1;
        char min= *min_element(s.begin()+1, s.end()-1);
        char max= *max_element(s.begin()+1, s.end()-1);
        if(s[0]==maxchar && s[n-1]==minchar && max < s[0] && s[n-1] < min){
            return 3;
        }else return 2;
    }
};