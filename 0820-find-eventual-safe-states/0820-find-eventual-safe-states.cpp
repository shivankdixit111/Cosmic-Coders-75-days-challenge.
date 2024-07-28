class Solution {
public:
       //reverse the edge all node will lead to terminal node except node forming
       // a cycle, after reversing edges terminal will become starting node of topo
       // sort do toposort find the required array 
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n+1],indegree(n+1,0);  
         queue<int> q;

        for(int i=0;i<n;i++) {
            vector<int> temp=graph[i];
            for(auto it:temp) {
                adj[it].push_back(i);
            }
        }
        for(int i=0;i<n;i++) {
            for(auto it:adj[i]) indegree[it]++;
        }
        for(int i=0;i<n;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int> topo;
        while(q.size()) {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]) {
                 indegree[it]--;
                 if(indegree[it]==0) {
                    q.push(it);
                 }
            } 
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};