class Solution {
public:
 int rec(int i, int buy,int transcation, vector<int> &prices, vector<vector<vector<int>>> &dp,int n) {
        if(i==n or transcation==0) {
            return 0;
        }

        if(dp[i][buy][transcation]!=-1) return dp[i][buy][transcation];

        int profit=0;
        if(buy==0) {
            int op1= -prices[i]+rec(i+1,1,transcation,prices,dp,n);  //transcation
            int op2=  rec(i+1,0,transcation,prices,dp,n);  //wait for better buying value
            profit=max(op1,op2);
        } else {  
            int op2= rec(i+1,1,transcation,prices,dp,n); //wait for better selling value
               int op1= prices[i]+rec(i+1,0,transcation-1,prices,dp,n);  //transcation
            profit=max(op1,op2);
        }
        return dp[i][buy][transcation]=profit;
    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

         return rec(0,0,2,prices,dp,n);
    }
};