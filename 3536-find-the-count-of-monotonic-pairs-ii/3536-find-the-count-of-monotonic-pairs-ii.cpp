class Solution {
public:
    const int mod = 1e9+7;

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
         vector<vector<int>> dp(n+1,vector<int>(1e3+1,0));
         for(int i=0;i<=nums[0];i++) {
            dp[0][i]=1;
         }

         for(int i=1;i<n;i++) {
            int ways=0,k=0;
            for(int j=0;j<=nums[i];j++) {
                if(k<= min(j,j+nums[i-1]-nums[i] )) {
                    ways = (ways + dp[i-1][k] )%mod;
                    k++;
                }
                dp[i][j] = ways;
            }
         }
 

         int ans=0;
         for(int i=0;i<=1000;i++) {
            ans = ( ans + dp[n-1][i] ) % mod;
         }
         return ans;
    }
};