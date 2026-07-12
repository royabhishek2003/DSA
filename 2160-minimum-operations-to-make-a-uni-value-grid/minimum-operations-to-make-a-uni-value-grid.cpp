class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        int rem= grid[0][0]%x;
        for(vector<int> &vec: grid){
            for( int &ele: vec){
                temp.push_back(ele);
                if(ele%x != rem) return -1;
            }
        }
        int n= temp.size();
        nth_element(temp.begin(), temp.begin()+n/2, temp.end());
        int target = temp[n/2];
        int ans=0;
        for(int &ele: temp){
            ans+= abs(ele-target)/x;
        }
        return ans;
        
    }
};