class Solution {
public:
     
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(10005,0);

        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum<target or (sum-target)&1) return 0;
        int s = (sum-target)/2;
        dp[0]=1;

        for(int i=0;i<n;i++) {
            for(int j=s;j>=nums[i];j--) {
                dp[j] = dp[j] + dp[j-nums[i]];
            }
        }

        return dp[s];
    }
};