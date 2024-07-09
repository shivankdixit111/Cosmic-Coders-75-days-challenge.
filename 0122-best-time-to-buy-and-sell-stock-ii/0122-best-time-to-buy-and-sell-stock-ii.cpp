class Solution {
public:
    int rec(int i, int buy, vector<int> &prices, vector<vector<int>> &dp,int n) {
        if(i==n) {
            return 0;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=0;
        if(buy==0) {
            int op1= -prices[i]+rec(i+1,1,prices,dp,n);  //transcation
            int op2=  rec(i+1,0,prices,dp,n);  //wait for better buying value
            profit=max(op1,op2);
        } else {  
            int op1= prices[i]+rec(i+1,0,prices,dp,n);  //transcation
            int op2= rec(i+1,1,prices,dp,n); //wait for better selling value
            profit=max(op1,op2);
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>> dp(n+1,vector<int>(2,0));
  
        //  return rec(0,0,prices,dp,n);

        for(int i=n-1;i>=0;i--) {
            int profit=0;
            for(int buy=0;buy<=1;buy++) {
                if(buy==0) {
                    int op1= -prices[i]+dp[i+1][1];  //transcation
                    int op2=  dp[i+1][0];  //wait for better buying value
                    profit=max(op1,op2);
                } else {  
                    int op1= prices[i]+dp[i+1][0];  //transcation
                    int op2= dp[i+1][1]; //wait for better selling value
                    profit=max(op1,op2);
                }
                 dp[i][buy]=profit;
            }
        }

        return dp[0][0];
    }
};