class Solution {
     
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<long long> dp(n+1,0);
        dp[1]=nums[0];
        for(int i =2;i<=n;i++) {
            long long op1=dp[i-1]+nums[i-1];
            long long op2=dp[i-2]+nums[i-2]+nums[i-1]*(-1);
            dp[i]=max(op1,op2);
        }
        return dp[n];
    }
};