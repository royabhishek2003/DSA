class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minele=INT_MAX;
        for(int ele: nums){
            if(ele<minele) minele=ele;
        }
        int result=0;
        for(int ele: nums){
            result+=(ele-minele);
        }
        return result;
    }
};