class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<long long> dp(5,-1e18);
        dp[0]=0;

        for(auto it:b) {
            for(long long i=4;i>=1;i--) {
                dp[i] = max( dp[i], dp[i-1] + a[i-1] * 1LL * it );
            }
        }
        return dp[4];
    }
};