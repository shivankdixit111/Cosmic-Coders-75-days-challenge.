class Solution {
public:
    int rec(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {

        if(idx==0) {
            if(amount % coins[0]==0) return 1;
            return 0;
        }

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int nottaken = rec(idx-1, amount, coins, dp);
        int taken=0;
        if(coins[idx] <= amount) {
          taken = rec(idx, amount-coins[idx], coins, dp);
        }

        return dp[idx][amount] = taken + nottaken;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));

        return rec(n-1,amount,coins,dp);
    }
};