class Solution {
public:
    vector<int> dp;
    int rec(int i, int n, vector<int> &nums) {
        if(i==n-1) return 0;
        if(i>=n) return 1e6;

        if(dp[i]!=-1) return dp[i];

        int mini = 1e6;
        for(int j=1;j<=nums[i];j++) {
            mini = min(mini, 1 + rec(i+j,n,nums));
        }
        return dp[i] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        return rec(0,n,nums);
    }
};