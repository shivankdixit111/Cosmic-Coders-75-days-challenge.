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
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(n-1,m-1,s,t,dp);
    }
};