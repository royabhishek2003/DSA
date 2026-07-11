class Solution {
public:
    int findcommon(int s1,int e1,vector<int> &nums1, int s2, int e2, vector<int> &nums2){
            unordered_set<int> s;
            for(int i= s1;i<=e1;i++){
                s.insert(nums1[i]);
            }
            int count=0;
            for(int i= s2;i<=e2;i++){
                if(s.find(nums2[i])!= s.end()) count++;
            }
            return count;
    }

    // approach -2 
    vector<int> segmentTree;
    int findleftcommon(long long i, int low, int high, int left, int right){
        if(right < low || left > high){
            return 0;
        }
        if(low >= left && high <= right){
            return segmentTree[i];
        }
        int mid = low +(high-low)/2;
        int l= findleftcommon(2*i+1, low, mid, left, right);
        int r= findleftcommon(2*i+2, mid+1,high ,left, right);
        return l+r;
    }

    void updatesegmentTree(long long i, int low, int high, int idx, int val){
        if(low == high){
            segmentTree[i]=val;
            return;
        }
        int mid = low +(high-low)/2;
        if(idx <= mid){
            updatesegmentTree(2*i+1, low, mid, idx,val);
        }
        else updatesegmentTree(2*i+2, mid+1, high, idx,val);
        segmentTree[i]= segmentTree[2*i+1] + segmentTree[2*i+2];

    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        // Neive Brute Force approach 
        // sare triplet nikalo nums1 ke now for each triplet check in nums 2 TC->O(n^4)
        // optimized brute force  Tc->O(n^2);
        unordered_map<int,int> mp;
        int n= nums1.size();
        for(int i=0;i<n;i++){
            mp[nums2[i]]=i;
        }
        // long long ans =0;
        // for(int i=1;i<n-1;i++){
        //     int j= mp[nums1[i]];
        //     int leftcommoncount= findcommon(0,i-1,nums1,0,j-1,nums2);
        //     int leftuncommoncount= i-leftcommoncount;
        //     int eleafter_j_in_nums2= n-j-1;
        //     int rightcommoncount= eleafter_j_in_nums2 - leftuncommoncount;
        //     ans += 1LL * leftcommoncount * rightcommoncount;
        // }

        // return ans;

        // 3rd approach using segment Tree
         // same mathematical approach just here we use segment tree to calculate the left commoncount because i need to find the leftcommon count for (n) queries which is segment Tree based problem 

        segmentTree.resize(4*n);
        long long ans =0;
        for(int i=0;i<n;i++){
            int idx = mp[nums1[i]];
            int leftcommoncount= findleftcommon(0,0,n-1,0,idx);
            int leftuncommoncount= i-leftcommoncount;
            int element_after_idx_in_nums2= n-idx-1;
            int rightcommonecount= element_after_idx_in_nums2 - leftuncommoncount;
            ans += 1LL * leftcommoncount * rightcommonecount;
            updatesegmentTree(0,0,n-1,idx,1);
        }
        return ans;


    }
};