class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
          vector<int> ans;
          set<int> st;
          for(int i=0;i<n;i++) st.insert(i);

          for(auto j:queries) {
            int u=j[0],v=j[1];
            auto it=st.lower_bound(u);
            auto it1=st.upper_bound(v);
            
            vector<int> toerase;
            for(;it!=it1;it++) {
                if(*it>u and *it<v) toerase.push_back(*it);
            }
            for(auto it: toerase) {
                st.erase(it);
            }
            ans.push_back(st.size()-1);
          }
          return ans;
    }
};