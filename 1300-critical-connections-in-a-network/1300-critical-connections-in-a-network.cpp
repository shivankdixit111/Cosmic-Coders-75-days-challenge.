class Solution {
public:
    void dfs(int node, int parent, vector<int> &low, vector<int> &disc, vector<int> &vis,int &timer
    ,vector<int> adj[], vector<vector<int>> &ans) { 
        vis[node]=1;
        low[node]=timer;
        disc[node]=timer;
        timer++; 
        
        for(auto it:adj[node]) {
             if(parent==it) continue;  //we reached to end of node
            if(!vis[it]) { 
               dfs(it,node,low,disc,vis,timer,adj,ans);
               low[node] = min(low[node],low[it]);
               cout<<node<<" "<<it<<" "<<low[it]<<" "<<disc[node]<<endl;
               if(low[it] > disc[node]) { //will always be greater if low[node] not updated by backedge and thus wiill form a bridge
                  ans.push_back({node,it});
               }
            } else {
                //there is a back edge
                low[node] = min(low[node],disc[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        for(auto it:connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        //tarzan algorithm
        vector<int> low(n+1,-1),disc(n+1,-1),vis(n+1,0);
        int timer=0;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(i,-1,low,disc,vis,timer,adj,ans);
            }
        }
        return ans;
    }
};