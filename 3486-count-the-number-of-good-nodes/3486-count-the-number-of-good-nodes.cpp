class Solution {
public:
    vector<int> sizes;
    int dfs(int node, vector<vector<int>> &edges,vector<int> &vis) {
         vis[node]=1; 
         if(edges[node].empty()) { 
            return 1;
         }
         int ans=0;

         for(auto it:edges[node]) {
            if(!vis[it])
             ans += dfs(it,edges,vis);
         } 
          return sizes[node]+=ans+1;
    }
     int cnt=0;
     void dfs1(int node, vector<vector<int>> &edges, vector<int> &vis) { 
         vis[node]=1; 
         map<int,int> mp1;

         for(auto it:edges[node]) {  
            if(!vis[it]) {
              mp1[sizes[it]]++;
              dfs1(it,edges,vis); 
            }
         } 
         if(mp1.size()==1 or mp1.size()==0) cnt++;
        //  return ans;
    }
    
  
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        sizes.resize(n+1,0);
        vector<vector<int>> adj(n+1);
        vector<int> vis(n+1,0);
        // sort(edges.begin(),edges.end());
        for(auto it:edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans= dfs(0,adj,vis);
    
        vector<int> vis1(n+1,0);
       
        // ans=0;

        dfs1(0,adj,vis1);
        return cnt;
    }
};