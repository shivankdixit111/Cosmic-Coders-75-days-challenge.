class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<long long,long long>> adj[n+1];
        for(auto it:roads) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        vector<long long> distance(n+1,1e18);
        map<long long,long long> mp;
        long long mod = 1e9+7;
        pq.push({0,0});  //{dist,src}
        mp[0]=1;
        distance[0]=0;

        while(pq.size()) {
            long long node=pq.top().second;
            long long dist=pq.top().first;
            pq.pop();
            
            // if(distance[node]<dist) continue;
            if(node==n-1) continue;
 
            for(auto it:adj[node]) {
                int v=it.first;
                int wt=it.second;
                if( dist + wt < distance[v] )  {
                    distance[v] = dist + wt;
                    pq.push({distance[v], v});
                    mp[v] = mp[node];
                } else if(dist + wt == distance[v]) {
                    mp[v]=(mp[v]%mod + mp[node]%mod)%mod; 
                }
            }
        }
        

        return mp[n-1]==0?1:mp[n-1];
        
    }
};