class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // optimal approach 
        string str="123456789";
        int i=0;
        int j=1;
        vector<int> ans;
        for(int i=0;i<9;i++){
            for(int j=i+1;j<9;j++){
                int num= stoi(str.substr(i,j-i+1));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};