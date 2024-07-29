class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>> pq;
        vector<int> distance(n+1,1e9);
        pq.push({0,k});  //{dist,src}
        distance[k]=0;

        while(pq.size()) {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            if(distance[node]<dist) continue;

            for(auto it:adj[node]) {
                int v=it.first;
                int wt=it.second;
                if( dist + wt < distance[v] )  {
                    distance[v] = dist + wt;
                    pq.push({distance[v], v});
                }
            }
        }
        int ans=-1e9;
        for(int i=1;i<=n;i++) {
            if(distance[i]==1e9) return -1;
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};