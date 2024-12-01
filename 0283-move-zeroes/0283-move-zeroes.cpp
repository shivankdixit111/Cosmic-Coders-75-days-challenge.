class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=1,n = nums.size();
        while(r<n) {
            if(nums[l]==0) {
                while(r<n and nums[r]==0) r++;
                if(r<n and nums[r]) {
                    nums[l] = nums[r];
                    nums[r] = 0;
                }
            }
            l++; r++;
        }
    }
};