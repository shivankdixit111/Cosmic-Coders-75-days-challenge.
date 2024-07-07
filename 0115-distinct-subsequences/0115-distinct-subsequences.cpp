class Solution {
public:
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

             
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int res=0;
        if(s[i]==t[j]) {
           res=rec(i-1,j-1,s,t,dp) + rec(i-1,j,s,t,dp);
        } else {
           res=rec(i-1,j,s,t,dp);
        }
        
        return dp[i][j] = res;
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // return rec(n-1,m-1,s,t,dp);
        int mod=1e9+7;
        
        for(int i=0;i<=n;i++) dp[i][0]=1;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int ans=0;
                if(s[i-1]==t[j-1]) {
                    ans=(dp[i-1][j-1]+dp[i-1][j])%mod;
                } else {
                    ans=dp[i-1][j];
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][m];
    }
};