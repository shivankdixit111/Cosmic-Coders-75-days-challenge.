class Solution {
public:
    bool ispal(int i, int j, string &s) {
        
        while(i<=j) {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    int rec(int i, int n, string &s, vector<int> &dp) {
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MAX;
        for(int k=i;k<n;k++) {
            if(ispal(i,k,s)) {
                ans=min(ans,1+rec(k+1,n,s,dp));
            }
        } 
        return dp[i]=ans;
    }

    int minCut(string s) {
        int n=s.length();
        vector<int> dp(n,-1);
        cout<<n<<endl;
        return rec(0,n,s,dp)-1;
    }
};