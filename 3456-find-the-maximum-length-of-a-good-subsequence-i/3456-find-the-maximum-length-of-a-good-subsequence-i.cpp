class Solution {
public:
    int maximumLength(vector<int>& arr, int k) {
        int n=arr.size();
          vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        for(int i=0;i<n;i++) {
            for(int j=i-1;j>=0;j--) {
                for(int k1=0;k1<=k;k1++) {

                    int diff=arr[i]!=arr[j];
                    if(k1+diff<=k) {
                        dp[i][k1+diff] = max( dp[i][k1+diff] , dp[j][k1] + 1);
                    }
                }
            }
        }
        
        int ans=LONG_MIN;

        for(int i=0;i<n;i++) {
            for(int j=0;j<k+1;j++) {
                ans=max(ans,dp[i][j]);
            }
        }
        return ans+1;
    }
};