
const int mod = 1e9+7;
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size(),start=-1,end=-1, zeroes=0,ans=1; 
        for(int i=0;i<n;i++) {
            if(nums[i]==1) {
                start = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) if(nums[i]==1) {end =i; break;}
        if(start==-1 and end==-1) return 0;
        if(start==-1 or end==-1) return 1;
        for(int i=start;i<=end;i++) {
            if(nums[i]==0) zeroes++;
            else {
                ans = (ans %mod *1LL*(zeroes+1)%mod)%mod;
                zeroes=0;
            }
        }
        return ans;
    }
};