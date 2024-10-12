class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums) 
        {   int mini = INT_MAX;
            for(int i=31;i>=0;i--) {
                if((1<<i)&it) {
                    int temp = it - (1<<i);
                    if((temp | (temp+1))==it) {
                        mini = min(mini,temp);
                    }
                }
            }
            ans.push_back(mini==INT_MAX?-1:mini);
        }
        return ans;
    }
};