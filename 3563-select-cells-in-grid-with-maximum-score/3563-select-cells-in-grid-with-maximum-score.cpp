class Solution {
public:
#define ff first 

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ss second  
    int maxi = INT_MIN;

    int rec(int val, int mask, map<int,vector<int>> &arr, vector<vector<int>> &dp) {
        if(val==0) return 0; 
        if(dp[val][mask]!=-1) return dp[val][mask];

        int nottake = rec(val-1, mask, arr,dp);
        int take=0;
        for(auto it: arr[val]) {
            if(((1<<it) & mask) ==0) {
               take = max(take, val + rec(val-1, mask | (1<<it), arr, dp));
            }
        }
        return dp[val][mask] = max(take,nottake);
    }
    
    int maxScore(vector<vector<int>>& grid) {
       
        map<int,vector<int>> arr;
        vector<int> values; 
        int n = grid.size(), m = grid[0].size();
 
        rep(i,0,n) {
            rep(j,0,m) {
                arr[grid[i][j]].push_back(i);
            }
        }
        vector<vector<int>> dp(101,vector<int>(1033,-1));
      
        return rec(100,0,arr,dp);
        
       

    }
};