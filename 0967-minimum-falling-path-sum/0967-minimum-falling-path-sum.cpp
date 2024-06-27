class Solution {
public:
  int rec(vector<vector<int>> &matrix,vector<vector<int>> &dp,int n,int m,int i,int j) {
        if(i==n) return 0;
        int left=1e5,down=1e5,right=1e5;

        if(dp[i][j]!=-1) return dp[i][j];

        if(j>0) left=matrix[i][j]+rec(matrix,dp,n,m,i+1,j-1);
        down=matrix[i][j]+rec(matrix,dp,n,m,i+1,j);
        if(j<m-1) right=matrix[i][j]+rec(matrix,dp,n,m,i+1,j+1);

        return dp[i][j]=min(down,min(left,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<m;j++) {
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                int down=1e5,left=1e5,right=1e5;
                down=matrix[i][j]+dp[i-1][j];
                if(j>0) left=matrix[i][j]+dp[i-1][j-1];
                if(j<m-1) right=matrix[i][j]+dp[i-1][j+1];
                
                dp[i][j]=min(down,min(left,right));
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<m;j++) 
          ans=min(ans,dp[n-1][j]);
        
        return ans;
    }
};