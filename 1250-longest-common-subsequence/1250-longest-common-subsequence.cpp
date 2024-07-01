class Solution {
    private:
       int rec(string &s,string &t,int i,int j,vector<vector<int>> &dp) {

           if(i<0 or j<0) return 0;

           if(dp[i][j]!=-1) return dp[i][j];

           if(s[i]==t[j]) {
             return dp[i][j]=1+rec(s,t,i-1,j-1,dp);
            }

           return dp[i][j] = max( rec(s,t,i-1,j,dp) , rec(s,t,i,j-1,dp) );
       }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n1=text1.length();
        int n2=text2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        vector<int> prev(n2+1,0);
        
        for(int i=1;i<=n1;i++) {
            vector<int> curr(n2+1,0);
            for(int j=1;j<=n2;j++) {
                if(text1[i-1]==text2[j-1]) {
                    curr[j]=max(curr[j],1+prev[j-1]);
                }
                curr[j]=max(curr[j],max(prev[j],curr[j-1]));
            }
            prev=curr;
        }
        return prev[n2];
    }
};