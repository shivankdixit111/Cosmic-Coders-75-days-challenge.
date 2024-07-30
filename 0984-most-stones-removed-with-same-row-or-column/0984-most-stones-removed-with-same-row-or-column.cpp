class Solution {
public:
 //tells whether u and v belong to same component in constant time O(1)--//
    vector<int> rank,parent,size;
  
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
  
    int removeStones(vector<vector<int>>& stones) {
         int rowMax=0,colMax=0;
         for(auto it:stones) {
            rowMax=max(rowMax,it[0]);
            colMax=max(colMax,it[1]);
         }
         DisjointSet(rowMax+colMax+1);
         
         //logic is all coordinate having same row or col will be a componet and we can delete every element except one
         // ans- size - total no of component
         set<int> st;
         for(auto it:stones) {
            int row=it[0];
            int col=it[1];
            findUnionBySize(row,col+rowMax+1);  //sothat col could be seperated from row
            st.insert(row);
            st.insert(col+rowMax+1); 
         }
         int cnt=0;
         for(auto it:st) {
            if(findUlp(it)==it) cnt++;
         }
         return stones.size()-cnt;
    }
};