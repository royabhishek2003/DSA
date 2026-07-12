class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<double> ans;
        multiset<int> left;
        multiset<int> right;
        int i=0;
        int j=0;
        while(j<n){
            if(left.empty() || left.size() <= right.size()){
                left.insert(nums[j]);
            }else right.insert(nums[j]);

            int leftmax= *(left.rbegin());
            if(!right.empty() && *(right.begin()) < leftmax){ //adjustment to make sure element is sorted fasion 
                left.erase(left.find(leftmax));
                int rightmin= *(right.begin());
                right.erase(right.find(rightmin));
                left.insert(rightmin);
                right.insert(leftmax);
            }

            while(j-i+1 > k){  // window is greater then k 
                if(left.find(nums[i]) != left.end()){
                    left.erase(left.find(nums[i]));
                }else right.erase(right.find(nums[i]));
                i++;
            }
            // balancing their size and maintining sorted fasion 
            while(left.size() > right.size() + 1) {
                    right.insert(*left.rbegin());
                    left.erase(prev(left.end()));
                }
            while (left.size() < right.size()) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            // window reached 
            if(j-i+1 == k){
                if(k%2!=0){  // odd side
                    ans.push_back(*(left.rbegin()));
                }else{  // even length 
                    ans.push_back( double((*(left.rbegin())) + double(*(right.begin())))/2.0);
                }
            }
            j++;
        }

        return ans;
    }
};