#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();

         vector<int> lis;
         
         for(int i=0;i<n;i++) {
            if(lis.empty() or lis.back()<nums[i]) {
                lis.push_back(nums[i]);
            } else {
                auto it=lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin();
                if(it==lis.size()) lis.push_back(nums[i]);
                else {
                    lis[it]=nums[i];
                }
            }
         }
         return lis.size();
    }
};