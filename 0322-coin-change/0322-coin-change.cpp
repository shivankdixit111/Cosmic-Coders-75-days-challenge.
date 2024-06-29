class Solution {
public:
    // int rec(int amount, vector<int>& coins, vector<int> &dp) {
    //     int n=coins.size();
    //     if(dp[amount]!=1e9)  return dp[amount];

    //     if(amount<=0) return 0;

    //     int ans=1e7;
    //     for(int i=0;i<n;i++) {
    //         if(amount>=coins[i]) {
    //             ans=min(ans,rec(amount-coins[i],coins,dp)+1);
    //         }
    //     }
    //     return dp[amount]=ans;
    // }

    int rec(int idx,int amount,vector<int> &coins, vector<vector<int>> &dp) {
         
        if(idx==0) {
             if(amount % coins[idx]==0) return amount / coins[idx];
            return 1e7;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int nottake=rec(idx-1,amount,coins,dp);
        int take=1e9;
        if(coins[idx]<=amount) {
            take=rec(idx,amount-coins[idx],coins,dp)+1;
        }

        return dp[idx][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        // vector<int> dp(100004,1e9);
        // dp[0]=0;

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<=amount;j++) {
        //          if(j>=coins[i]) {
        //             dp[j]=min(dp[j],dp[j-coins[i]]+1);
        //          }
        //     }
        // } 

        // return dp[amount]==1e9?-1:dp[amount];  
        // int ans= rec(amount,coins,dp);
        // return ans==1e7?-1:ans;

        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        int ans=rec(n-1,amount,coins,dp);
        return ans==1e7?-1:ans;
    } 
};