class Solution {
public: 

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
 

        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
        vector<int> prev(amount+1,1e9);
      
        for(int j=0;j<=amount;j++) {
            if( j % coins[0] == 0) prev[j] = j / coins[0] ;
        }

        for(int i=1;i<n;i++) {
            vector<int> curr(amount+1,1e9);
            for(int j=0;j<=amount;j++) {
                    int nottake = prev[j];
                    int take=1e9;
                    if(coins[i]<=j) {
                        take = 1 + curr[j-coins[i]];
                    }
                curr[j]=min(take,nottake);
            }
            prev=curr;
        }

        return prev[amount]==1e9?-1:prev[amount];
    } 
};