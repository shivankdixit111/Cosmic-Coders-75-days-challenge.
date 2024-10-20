class Solution {
public: 
    int rec(int i,int n, string &s, vector<string> &wordDict, vector<int> &dp) {
        if(i==n) return true;
        
        if(dp[i]!=-1) return dp[i];
        
        bool ans = false;
        for(auto it:wordDict) {
            if(s.substr(i,it.length())==it) {
               ans = ans | rec(i+it.length(),n,s,wordDict,dp) ;
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n = s.length();
         vector<int> dp(n+1,-1);
         return rec(0,n,s,wordDict,dp);
    }
};