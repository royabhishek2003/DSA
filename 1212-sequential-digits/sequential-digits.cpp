class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // optimal approach 
        string str="123456789";
        int i=0;
        int j=1;
        set<int> s;
        for(int i=0;i<10;i++){
            for(int j=i+1;j<10;j++){
                int num= stoi(str.substr(i,j-i+1));
                if(num >= low && num <= high) s.insert(num);
            }
        }
        vector<int> ans;
        auto it = s.begin();
        while(it!=s.end()){
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};