class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // first approach using ime complexity of o(n^2)
        // second best approach  is to sort the array is apply binary search over thre Time complexity O(n^2)
        int n= arr1.size();
        int m= arr2.size();
        sort(arr2.begin(), arr2.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int low=0;
            int high=m-1;
            int find= arr1[i];
            while(low <= high){
                int mid = low + (high-low)/2;
                if(arr2[mid] <find){
                    low = mid+1;
                }
                else high = mid-1;
            }
            if(low <m && abs(find - arr2[low])<=d) continue ;
            if(high >=0 && abs(find - arr2[high]) <=d) continue;
            ans+=1;
        }
        return ans;
    }
};