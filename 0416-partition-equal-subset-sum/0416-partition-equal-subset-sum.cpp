class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(sum&1) return false;

        bitset<100000> bit;
        bit[0]=1;
        for(int i=0;i<n;i++) {
            bit=bit|(bit<<nums[i]);
        }

        if(bit[target]) return true;
        return false;

    }
};