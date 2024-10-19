class Solution {
public:
    int rec(int i, string s, vector<int> &dp) {
        if(i>s.length()) return 0;
        if(i==s.length()) return 1;

        if(dp[i]!=-1) return dp[i];
        
        int ans = 0;
        //1 length();
        if(stoi(s.substr(i,1))>0)
        ans += rec(i+1,s,dp);
        // 2 length()
        string t = s.substr(i,2);
        if(stoi(t) <= 26 and t[0]!='0' ) {
            ans += rec(i+2,s,dp);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return rec(0,s,dp);
    }
};