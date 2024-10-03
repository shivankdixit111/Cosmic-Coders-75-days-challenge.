class Solution {
public:
    const int mod = 1e9+7;
    int rec( int i, int f, vector<int> &nums, vector<vector<int>> &dp) {
        if(i==nums.size()) return dp[i][f]=1;

        if( dp[i][f]!=-1 ) return dp[i][f];
        
        int ans=0,flag=0;
        for(int j=f;j<=nums[i];j++) {
            if(i==0 or (nums[i]-j)<=(nums[i-1]-f)) {
                ans += rec(i+1,j,nums,dp);
                ans %= mod;
                flag = 1;
            }
        }
        
        if(!flag) return dp[i][f]=0;

        return dp[i][f]=ans;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(1e3+5,-1));
        return rec(0,0,nums,dp);
    }
};