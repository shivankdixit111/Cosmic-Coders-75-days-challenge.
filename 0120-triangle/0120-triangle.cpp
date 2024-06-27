class Solution {
public:
    int rec(vector<vector<int>> &triangle,vector<vector<int>> &dp,int n,int i,int j) {
        if(i==n) return 0;
        int left=1e5,down=1e5,right=1e5;

        if(dp[i][j]!=-1) return dp[i][j];

         
        down=triangle[i][j]+rec(triangle,dp,n,i+1,j);
        right=triangle[i][j]+rec(triangle,dp,n,i+1,j+1);

        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(triangle,dp,n,0,0);
    }
};