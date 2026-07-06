class Solution {
public:
    bool isprime(int &n){
        for(int i=2;i*i<=n;i++){
            if(n%i == 0) return false;
        }

        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        
        int dx[] = {-1, -1, -1,  0, 0, 1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1,-1, 0, 1};
        int n= mat.size();
        int m= mat[0].size();

        unordered_map<int,int> mp;

        int ans=-1;
        int maxfreq=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                for(int k=0;k<8;k++){
                    int num=0;
                    int x=i;
                    int y=j;
                    while(x>=0 && x<n && y>=0 && y<m){
                        num= num*10 + mat[x][y];
                        if(num>10 && isprime(num)){
                            mp[num]++;
                            if(mp[num] > maxfreq){
                                ans = num;
                                maxfreq=mp[num];
                            }
                            else if(mp[num]== maxfreq && num > ans){
                                ans=num;
                            }
                        }
                        x= x + dx[k];
                        y= y + dy[k];
                    }
                }
            }
        }

        return ans;

    }
};