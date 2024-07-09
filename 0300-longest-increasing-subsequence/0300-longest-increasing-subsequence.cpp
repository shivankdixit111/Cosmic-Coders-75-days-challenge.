#include<bits/stdc++.h>
class Solution {
public:
    int rec(int i, int prev, vector<int> &nums,vector<vector<int>> &dp) {
        if(i==nums.size()) {
            return 0;
        }

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int nottake=rec(i+1,prev,nums,dp);
        int take=-1e5;
        if(prev==-1 or nums[i]>nums[prev]) {
            take=max(1+rec(i+1,i,nums,dp),rec(i+1,prev,nums,dp));
        }
        return dp[i][prev+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();

        //  vector<int> lis;
         
        //  for(int i=0;i<n;i++) {
        //     if(lis.empty() or lis.back()<nums[i]) {
        //         lis.push_back(nums[i]);
        //     } else {
        //         auto it=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
        //         if(it==lis.size()) lis.push_back(nums[i]);
        //         else {
        //             lis[it]=nums[i];
        //         }
        //     }
        //  }
        //  return lis.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }
};