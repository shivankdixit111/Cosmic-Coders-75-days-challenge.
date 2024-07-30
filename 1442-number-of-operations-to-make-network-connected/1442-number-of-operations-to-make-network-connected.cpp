class Solution {
public:
  vector<int> parent,size;
   void DisjointSet(int n) { 
       parent.resize(n+1);
       size.resize(n+1,1);

       for(int i=0;i<=n;i++) parent[i]=i;
    
    }

    int findUlp(int node) {
        if(node==parent[node]) return node;

        return parent[node]=findUlp(parent[node]);
    }

   
    void findUnionBySize(int u,int v) {  //it stores the size as rank gets distorted while path compression
         int ulp_u=findUlp(u);
         int ulp_v=findUlp(v);

         if(ulp_u==ulp_v) return;

         if( size[ulp_u] > size[ulp_v] ) {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
         } else {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
         }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
         vector<vector<int>> edges;
         for(auto it:connections) {
            edges.push_back({1,it[0],it[1]});  //{wt,u,v}
         }
         sort(edges.begin(),edges.end());
         DisjointSet(n+2);
         int cnt=0;
         int checknode=-1;
         for(auto it:edges) {
            int wt=it[0];
            int u=it[1];
            int v=it[2];
            checknode=u;
            if(findUlp(u) != findUlp(v)) {  //doesn't belong to same component cantake otherwize they wiill form a cycle
               cnt++;
            }
            findUnionBySize(u,v);
         }
         int rem=edges.size()-cnt;
         int temp=0; 
         for(int i=0;i<n;i++) {
            if(findUlp(checknode) != findUlp(i)) {
                rem--;
                temp++;
            }
            findUnionBySize(checknode,i);
         }
         return rem>=0?temp:-1;
    }
};