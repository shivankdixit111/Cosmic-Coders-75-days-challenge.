class Solution {
public: 
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0LL ,ans=0;

        for(int i=0;i<n-1;i++) {
           maxi = max(maxi,(long long)nums[i]);
           ans+=maxi;
        }
        return ans;
    }
};