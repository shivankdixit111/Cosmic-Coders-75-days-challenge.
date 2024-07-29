class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> q;
        vector<pair<int,int>> adj[n+1];

        for(auto it:flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        q.push({0,{0,src}});  // {dist,{level,src}}
        vector<int> distance(n+1,1e9);
        distance[src]=0;

        while(q.size()) {
            int node=q.front().second.second;
            int level=q.front().second.first;
            int dist= q.front().first;
            
            // cout<<dist<<" "<<level<<" "<<node<<endl;
            q.pop();
            // if(distance[node]<dist) continue;

            
            for(auto it:adj[node]) {
                int wt=it.second;
                int v=it.first; 
                if((dist + wt < distance[v]) and level<=k) {
                    distance[v] = dist + wt;
                    q.push({distance[v],{level+1,v}});
                  
                }
            }
        }
        if(distance[dst]!=1e9) return distance[dst];
        return -1;
    }
};