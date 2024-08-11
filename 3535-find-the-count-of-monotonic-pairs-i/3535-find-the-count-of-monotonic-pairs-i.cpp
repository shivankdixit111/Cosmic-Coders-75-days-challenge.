class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n=nums.size(), mod = 1e9+7;

        vector<vector<int>> dp(n+1,vector<int>(51,0));

        for(int i=0;i<=nums[0];i++) dp[1][i]=1;

        for(int i=2;i<=n;i++) {
            for(int j=0; j<= nums[i-1]; j++) {
                int other = nums[i-1] - j;

                for(int k=0; k<= min(j,nums[i-2]) ; k++) {
                    int otherprev = nums[i-2] - k; 
                    
                    if(otherprev >= other) {
                        dp[i][j] = (dp[i][j]%mod + dp[i-1][k]%mod ) %mod;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<=50; i++) {
            ans= (dp[n][i]%mod + ans%mod) %mod;
        }
        return ans;
    }
};