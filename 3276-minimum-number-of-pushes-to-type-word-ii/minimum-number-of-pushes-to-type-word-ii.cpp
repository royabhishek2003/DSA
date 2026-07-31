class Solution {
public:
    int minimumPushes(string word) {
         vector<int> freq(26);
        for(char &ch: word) freq[ch-'a']++;
        auto mycomp= [&](int a, int b){
                return a>b;
        };
        sort(freq.begin(),freq.end(), mycomp);

        int round=1;
        int ans=0;
        int key=2;
        for(int i=0;i<26;i++){
            if(freq[i]==0){
                return ans;
            }
            if(key>9){
                key=2;
                round+=1;
            }
            ans += freq[i]*round;
            key++;
        }
        return ans;
    }
};