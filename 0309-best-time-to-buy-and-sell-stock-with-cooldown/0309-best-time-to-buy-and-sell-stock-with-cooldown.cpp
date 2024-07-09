class Solution {
public:
     int rec(int i, int buy, vector<int> &prices, vector<vector<int>> &dp,int n) {
        if(i>=n ) {
            return 0;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy==0) {
            int op1= -prices[i]+rec(i+1,1,prices,dp,n);  //
            int op2=  rec(i+1,0,prices,dp,n);  //wait for better buying value
            profit=max(op1,op2);
        } else {  
            int op2= rec(i+1,1,prices,dp,n); //wait for better selling value
               int op1= prices[i]+rec(i+2,0,prices,dp,n);  //
            profit=max(op1,op2);
        }
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>> dp(n+1,vector<int>(3,-1));

         return rec(0,0,prices,dp,n);
    }
};