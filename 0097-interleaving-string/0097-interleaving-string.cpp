class Solution {
public:
    bool rec(int i, int j,int k, int n,int m, string &s1, string &s2, string &s3,
    vector<vector<vector<int>>> &dp) {
         if(k==s3.length()){
            return (i==n and j==m);
         }
         if(dp[i][j][k]!=-1) return dp[i][j][k];

         bool ans = false;         
         if(i<n and s1[i]==s3[k]) {
            ans = ans | (rec(i+1,j,k+1,n,m,s1,s2,s3,dp) or rec(i+1,j,k,n,m,s1,s2,s3,dp));
         }
         if(j<m and s2[j]==s3[k]) {
            ans = ans | (rec(i,j+1,k+1,n,m,s1,s2,s3,dp) or rec(i,j+1,k,n,m,s1,s2,s3,dp));
         }
         return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
         int n = s1.length(),m=s2.length();
         if(n+m != s3.length()) return false;
         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(s3.length()+1,-1)));
         return rec(0,0,0,n,m,s1,s2,s3,dp);
    }
};