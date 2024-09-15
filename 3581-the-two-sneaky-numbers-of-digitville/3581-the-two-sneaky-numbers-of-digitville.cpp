class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) {
            mp[it]++;
        }
        vector<int> temp;
      for(auto it:mp) {
        if(it.second==2) temp.push_back(it.first);
      }
      return temp;
    }
};