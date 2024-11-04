class Solution {
public:
    vector<vector<int>> dp;
    int rec(int idx, int mask, int n) {
        if(idx==n) { 
            return mask==(1<<n)-1;
        }
        if(dp[idx][mask]!=-1) return dp[idx][mask];

        int ans = 0;
        for(int i=0;i<n;i++) {
            if(!((1<<i)&mask) and ((i+1)% (idx+1)==0) or ((idx+1)%(i+1)==0)) {
                ans += rec(idx+1, mask|(1<<i), n);
            }
        }
        return dp[idx][mask] = ans;
    }
    int countArrangement(int n) {
        dp.resize(n+1,vector<int>((1<<n),-1));
        return rec(0,0,n);
    }
};