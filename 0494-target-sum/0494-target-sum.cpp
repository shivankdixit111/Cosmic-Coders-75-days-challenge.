class Solution {
public:
    int rec(int idx,int target,vector<int> &nums,vector<vector<int>> &dp) {
        
        if(idx==0) {
            if(target==0 and nums[0]==0) return 2;
            if(nums[0]==target or  target==0) return 1;
            return 0;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int nottaken = rec(idx-1,target,nums,dp);
        int taken=0;
        if(nums[idx]<=target) {
          taken = rec(idx-1,target-nums[idx],nums,dp);
        }

        return dp[idx][target] = taken + nottaken ;
    }
     
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<int> dp(10005,0);

        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum<target or (sum-target)&1) return 0;
        int s = (sum-target)/2;
       
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        return rec(n-1,s,nums,dp);
    }
};