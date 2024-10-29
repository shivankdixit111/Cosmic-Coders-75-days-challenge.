class Solution {
public:
    vector<vector<int>> dp;
    int rec(int n,int cnt) {
        if(n==0) {
            if(cnt>=2) return 1;
            return -1e3;
        }
        if(dp[n][cnt]!=-1) return dp[n][cnt];

        int ans = INT_MIN;        
        for(int i=1;i<=60;i++) {
            if(i<=n) {
                ans = max(ans, i * rec(n-i,cnt+1));
            } else {
                break;
            }
        }
        return dp[n][cnt] = ans;
    }
    int integerBreak(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return rec(n,0);
    }
};