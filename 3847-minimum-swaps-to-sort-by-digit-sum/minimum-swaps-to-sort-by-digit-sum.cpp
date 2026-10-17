class Solution {
public:
    int findsum(int n){
        int sum=0;
        while(n){
            sum+= n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n= nums.size();
        vector<int> temp= nums;
        sort(nums.begin(),nums.end(), [&](int &a, int &b){
            int sum1= findsum(a);
            int sum2= findsum(b);
            if(sum1 != sum2){
                return sum1<sum2;
            }
            return a<b;
        });

        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[temp[i]]=i;
        }
        int swaps=0;
        for(int i=0;i<n;i++){
            if(temp[i]!=nums[i]){
                swaps+=1;
                int required=nums[i];
                int idx = mp[required];
                // swap
                int t= temp[i];
                temp[i]= required;
                temp[idx]=t;
                // update index entry in map
                mp[required]=i;
                mp[t]=idx;
            }
        }
        return swaps;
    }
};