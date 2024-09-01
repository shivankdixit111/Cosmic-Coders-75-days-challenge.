class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
         
         vector<int> ans;
         multiset<int> st;
         for(auto it:queries) {
            int u = it[0];
            int v = it[1]; 

             int dist  = abs(u) + abs(v);

           
            if(st.size()>=k) {  
                         if(dist<(*(--st.end()))) {
                            st.erase(--st.end());
                            st.insert(dist);
                         }

                   ans.push_back(*(--st.end())); 
            } else { 
                  st.insert(dist);
                  
                  if(st.size()==k) ans.push_back(*(--st.end()));
                
                    else 
                ans.push_back(-1);
            }
         }
         return ans;
         
    }
};