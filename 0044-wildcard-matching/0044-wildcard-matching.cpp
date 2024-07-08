class Solution {
public:
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
         int n=s.length();
         int m=t.length();

        if(i==n and j==m) return true;

        if(i==n and j<m) {
            int cnt=0;
            for(int k=j;k<m;k++) { 
                if(t[k]!='*') return false;
            }
            return true;
        }

        if(j==m and i<n) return false; 

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j] or t[j]=='?') {
            return dp[i][j]=rec(i+1,j+1,s,t,dp);
        } else {
            if(t[j]=='*')
            return dp[i][j]=rec(i+1,j,s,t,dp) || rec(i,j+1,s,t,dp);
            else 
            return dp[i][j]=false;
        }
    }

    bool isMatch(string s, string p) {
         int n=s.length();
         int m=p.length();

         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         return rec(0,0,s,p,dp);
    }
};