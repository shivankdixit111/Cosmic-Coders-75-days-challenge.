class Solution {
public:
class DisjointSet {
  public:
    vector<int> rank,parent;
    DisjointSet(int n) {
       rank.resize(n+1,0);
       parent.resize(n+1);

       for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
    }

    void findUnionByRank(int u,int v) {
        int u_ulp=findUlp(u);
        int v_ulp=findUlp(v);

        if(u_ulp==v_ulp) return;

        int urank=rank[u_ulp],vrank=rank[v_ulp];

        if(urank==vrank) {
            parent[v_ulp]=u_ulp;
            rank[u_ulp]++;
        } else if(urank>vrank) {
            parent[v_ulp]=u_ulp;
        } else {
            parent[u_ulp]=v_ulp;
        }
        
      }
   };
    long long countPairs(int n, vector<vector<int>>& edges) {
         DisjointSet ds(n+2);

        for(int i=0;i<edges.size();i++) {
            int u=edges[i][0],v=edges[i][1];
            ds.findUnionByRank(u,v);
        }
       
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[ds.findUlp(i)]++;
        }

       

        long  long ans=0;
       
        for(int i=0;i<n;i++) {
            ans = ans + (n-mp[ds.findUlp(i)]);
        }

        return ans/2;
    }
};