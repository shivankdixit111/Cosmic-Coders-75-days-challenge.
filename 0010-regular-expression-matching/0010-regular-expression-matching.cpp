class Solution {
public:
   int dp[22][22];
    bool rec(int i,int j, string &s, string &t) {
        if(j>=t.length()) {
            return i==s.length();
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool check = false;
        if(i<s.length() and s[i]==t[j] or (t[j]=='.')) check = true;

        if(j<t.length()-1 and t[j+1]=='*') {
            int nottake = rec(i,j+2,s,t);
            int take = false; 
            if(i<s.length()) take = check and rec(i+1,j,s,t);

            return dp[i][j] = take | nottake;
        }

        return dp[i][j] = check and rec(i+1,j+1,s,t);
    }
     
    bool isMatch(string s, string p) {
         for(int i=0;i<22;i++) 
            for(int j=0;j<22;j++) 
               dp[i][j] = -1;
         return rec(0,0,s,p);
    }
};