class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n= nums.size();
        int ans=INT_MAX;
        deque<int> dq;
        vector<long long> prefix(n);
        int j=0;
        while(j<n){
            if(j==0) prefix[j]=nums[j];
            else prefix[j]= nums[j]+prefix[j-1];

            if(prefix[j] >= k) ans= min(ans, j+1);

            while(!dq.empty() && prefix[j] - prefix[dq.front()] >=k){
                ans = min(ans, j- dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefix[j] <= prefix[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }

        if(ans==INT_MAX) return -1;
        else return ans;

    }
};