class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1,j=1,maxi=nums[0],n=nums.size();
        while(j<n){
            if(maxi==nums[j]) j++; 
            else {
               swap(nums[i],nums[j]);
               maxi = nums[i];
               i++; j++;
            }
        }
        return i;
    }
};