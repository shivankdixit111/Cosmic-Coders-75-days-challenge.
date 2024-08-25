class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(int i=0;i<n;i++) {
            pq.push({nums[i],i});
        }

        while(k--) {
            pq.push({pq.top().first*multiplier,pq.top().second});
            pq.pop();
        }
        vector<int> ans(n);
        while(pq.size()) {
            ans[pq.top().second]= (pq.top().first);
            pq.pop();
        }
        return ans;
    }
};