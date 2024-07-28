class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, int col,vector<int> &color) { 
        color[node]=col;

        for(auto it:adj[node]) {
            if(color[it]==-1) {
                if(dfs(it,adj,!col,color)==false) return false ;
            } else if(col==color[it]) return false; 

        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) { 
         int n=graph.size();

         vector<int> color(101,-1);
         for(int i=0;i<n;i++) {
            if(color[i]==-1) {
                if(dfs(i,graph,0,color)==false) return false;
            }
         }
         return true;
    }
};