class Solution {
public:
    int rec(vector<int> &nums,vector<int> &dp,int i) {
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        return  dp[i]=max(rec(nums,dp,i-1),nums[i]+rec(nums,dp,i-2));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n+1,-1);
       
        dp[0]=nums[0]; 

        // if(n==1) return nums[0];
       
        // if(n==2) return max(nums[0],nums[1]);
         
        return rec(nums,dp,n-1);
    }
};