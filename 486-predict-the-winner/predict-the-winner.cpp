class Solution {
public:
    bool solve (int i, int j, auto &nums, int p1, int p2,int count){
        if(i>j){
            return p1>=p2;
        }
        if(count%2==0){ // p1's turn 
            bool takefirst= solve(i+1,j,nums,p1+nums[i],p2,count+1);
            bool takelast= solve(i,j-1,nums,p1+nums[j],p2,count+1);

            return takefirst || takelast;

        }else{  // p2's turn
            bool takefirst= solve(i+1,j,nums,p1,p2+nums[i],count+1);
            bool takelast= solve(i,j-1,nums,p1,p2+nums[j],count+1);

            return takefirst && takelast; // plaer 2 choose their optimally move 
        }
        
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int count=0;
        int n= nums.size();
        return solve(0,n-1,nums,0,0,0);
    }
};