class Solution {

public:
    
    int rec(string &s, string &temp, int i, int j, vector<vector<int>> &dp) {
        if(i<0 or j<0) return 0;

        int ans=0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==temp[j]) {
           return dp[i][j] = 1+rec(s,temp,i-1,j-1,dp);
        } 
           return dp[i][j] = max(rec(s,temp,i-1,j,dp),rec(s,temp,i,j-1,dp));


        return dp[i][j]=ans;
    }

    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string temp=s;
        reverse(temp.begin(),temp.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        // cout<<s<<" "<<temp<<endl;

        return rec(s,temp,n-1,n-1,dp);
    }
};