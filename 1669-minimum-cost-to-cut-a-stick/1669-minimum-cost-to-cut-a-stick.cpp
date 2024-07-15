class Solution {
public:
    long rec(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i>j) return 0LL;

        if(dp[i][j]!=-1) return dp[i][j];

        long mini=INT_MAX;
        for(int k=i;k<=j;k++) {
            long ans=abs(cuts[j+1]-cuts[i-1]) + rec(i,k-1,cuts,dp) + rec(k+1,j,cuts,dp);
            mini=min(mini,ans);
        } 
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        
        return rec(1,cuts.size()-2,cuts,dp);
    }
};