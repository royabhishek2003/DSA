class Solution {
public:
    string findkey(string &s, int &i){
        i++;
        string key="";
        while(s[i]!=')'){
            key+=s[i];
            i++;
        }
        i++;
        return key;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(vector<string> &vec: knowledge){
            mp[vec[0]]=vec[1];
        }
        string ans="";
        int n= s.length();
        int i=0;
        while(i<n){
            if(s[i]=='('){
                string key= findkey(s,i);
                if(mp.find(key)!=mp.end()){
                    ans+=mp[key];
                }else ans+="?";
            }else{
                ans+=s[i];
                i+=1;
            }
        }
        return ans;
    }
};