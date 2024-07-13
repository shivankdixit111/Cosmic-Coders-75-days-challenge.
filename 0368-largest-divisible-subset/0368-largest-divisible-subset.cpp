class Solution {
public:
    int gcd(int a,int b) {
        return b?gcd(a,a%b):a;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
         vector<int> dp(n,0);
         vector<int> hash(n,0);
         sort(nums.begin(),nums.end());

         for(int i=0;i<n;i++) {
            hash[i]=i;
            for(int previdx=0;previdx<i;previdx++) {
                if(nums[i]>nums[previdx] and 1+dp[previdx]>dp[i] and nums[i]%nums[previdx]==0) {
                    dp[i]=1+dp[previdx];
                    hash[i]=previdx;
                }
            }
         }

         int ans=*max_element(dp.begin(),dp.end());
         int idx=-1;
         for(int i=0;i<n;i++) {
            if(ans==dp[i]) {
                idx=i;
                break;
            }
         }

         vector<int> ldsubset;
         ldsubset.push_back(nums[idx]);

         while(hash[idx]!=idx) {
                idx=hash[idx];
            ldsubset.push_back(nums[idx]);
         }

         return ldsubset;
    }
};