class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minele=prices[0];
        int ans=0;
        int n= prices.size();
        for(int i=1;i<n;i++){
            ans= max(ans, prices[i]-minele);
            minele= min(minele,prices[i]);
        }
        return ans;
    }
};