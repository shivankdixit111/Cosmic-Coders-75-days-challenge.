class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=0;
            }
        }

        if(arr[n-1][m-1]==0)
        dp[n-1][m-1]=1;

        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i<n-1 and arr[i][j]==0) dp[i][j]+=dp[i+1][j];
                if(j<m-1 and arr[i][j]==0) dp[i][j]+=dp[i][j+1];
            }
        }

        return (int)dp[0][0];
    }
};