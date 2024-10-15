class Solution {
public:
    const int mod = 1e9+7;
    int mod_mul(int x,int y) {
        long long ans = (x %mod * 1LL * y%mod)%mod;
        return ans;
    }
    vector<vector<int>> dp;
    int rec(int i,int stage, int x, int y, int n) {
        if(i==n) {
            return 1;
        }
        if(dp[i][stage] != -1) return dp[i][stage];

        int ans = mod_mul( mod_mul((x-stage) , y) , rec(i+1, stage+1, x, y, n));  //new stage
        ans = (ans % mod +  mod_mul(stage , rec(i+1, stage, x, y, n)) % mod)%mod; //old stage 

        return dp[i][stage] = ans;
    }
    int numberOfWays(int n, int x, int y) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return rec(0,0,x,y,n);
    }
};