class Solution {
public:
    int findmax(vector<int> &nums, int a, int j){
        int maxele=INT_MIN;
        for(int i=a;i<=j;i++){
            maxele= max(maxele,nums[i]);
        }
        return maxele;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Brute Force 
        // int n= nums.size();
        // int i=0;
        // int j=k-1;
        // vector<int>ans;
        // while(j<n){
        //     int maxele= findmax(nums,i,j);
        //     ans.push_back(maxele);
        //     i+=1;
        //     j+=1;
        // }
        // return ans;

        // optimal approach using deque 

        int n= nums.size();
        int i=0;
        int j=0;
        vector<int>ans;
        deque<int> dq;
        while(j<n){
            while(!dq.empty() && nums[j] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            while(j-i+1 > k){
                if(nums[dq.front()] == nums[i]){
                    dq.pop_front();
                }
                i++;
            }
            if(j-i+1 == k ) ans.push_back(nums[dq.front()]);
            j++;
        }

        return ans;
    }
};