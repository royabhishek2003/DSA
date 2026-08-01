class Solution {
public:
    int n;
    bool solve(int i, int j, auto &nums,int p1, int p2,int count){
        if(i>j){
            if(p1 >= p2) return true;
            return false;
        }
        if(count%2==0){
           
            bool pickfront= solve(i+1,j,nums,p1+nums[i],p2,count+1);
            bool picklast= solve(i,j-1,nums,p1+nums[j],p2,count+1);
            if(pickfront || picklast) return true;
            return false;
        }else{
           
            bool pickfront= solve(i+1,j,nums,p1,p2+nums[i],count+1);
            bool picklast= solve(i,j-1,nums,p1,p2+nums[j],count+1);
            if(pickfront && picklast) return true;
            return false;
        }
        return false;
       
        



    }
    bool predictTheWinner(vector<int>& nums) {
        // int player1=0;
        // int player2=0;
        // int n= nums.size();
        // int i=0;
        // int j=n-1;
        // int count=0;
        // while(i<=j){
        //     if(count%2 == 0){  // player1 turn
        //         if(nums[i]>nums[j]){
        //             player1+=nums[i];
        //             i++;
        //         }else{
        //             player1+=nums[j];
        //             j--;
        //         }
        //     }else{ // player 2 turn
        //         if(nums[i]>nums[j]){
        //             player2+=nums[i];
        //             i++;
        //         }else{
        //             player2+=nums[j];
        //             j--;
        //         }
        //     }
        //     count+=1;
        // }

        // if(player1 >= player2) return true;
        // return false;

        // recursive solution 
        n= nums.size();
        int p1=0;
        int p2=0;
        if(solve(0,n-1,nums,p1,p2,0)) return true;
        return false;
       
    }
};