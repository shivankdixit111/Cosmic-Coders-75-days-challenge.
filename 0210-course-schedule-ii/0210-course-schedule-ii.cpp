class Solution {
public:     
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses+1];
         for(auto it:prerequisites) {
            adj[it[0]].push_back(it[1]);
         }

         vector<int> topo,indegree(numCourses+1,0);
         queue<int> q;
         for(int i=0;i<numCourses;i++) {
            for(auto it:adj[i]) {
                indegree[it]++;
            }
         }
         for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) q.push(i);
         }
         while(q.size()) {
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it:adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
         }
         reverse(topo.begin(),topo.end());
         if(topo.size()==numCourses) return topo;
         return {};
    }
};