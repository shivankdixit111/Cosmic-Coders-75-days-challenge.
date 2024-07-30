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

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        DisjointSet(n*m+1);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                //making component of graph
                if(grid[i][j]==1) {
                    if(i>0 and grid[i-1][j]==1) findUnionBySize((i-1)*m+j,i*m+j);
                    if(j>0 and grid[i][j-1]==1) findUnionBySize(i*m+j,i*m+j-1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int a=0;
                if(grid[i][j]==1) {
                   a+=size[findUlp(i*m+j)];
                } else {
                   a++;
                   set<int> st;
                   if(i>0 and grid[i-1][j]==1) st.insert(findUlp((i-1)*m+j));
                   if(i<n-1 and grid[i+1][j]==1) st.insert(findUlp((i+1)*m+j));
                   if(j>0 and grid[i][j-1]==1) st.insert(findUlp(i*m+j-1));
                   if(j<m-1 and grid[i][j+1]==1) st.insert(findUlp(i*m+j+1));
                   
                   for(auto it:st) {
                      a+=size[it];
                   }
                }
                ans=max(ans,a);
            }
        }
        return ans;
    }
};