class Solution {
public:
    int diameter(int node, vector<vector<int>> &adj, vector<int> &vis,int &ans) {
        vis[node]=1; 
        int maxi = 0,sum=0,m1=0,m2=0;

        for(auto it:adj[node]) {
            if(!vis[it]) {
                int d = diameter(it, adj, vis, ans);
                maxi = max( maxi, d ); 
                // chose two maximum length
                if(d > m1) {
                    m2 = m1;
                    m1 = d;
                } else if(d > m2) {
                    m2 = d;
                }
                sum = m1 + m2;
            }
        }  

        ans = max(ans,sum);

        return 1 + maxi;
    } 

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
         int n = edges1.size(), m = edges2.size();

         vector<int> vis1(n+1,0), vis2(m+1,0);
         vector<vector<int>> adj1(n+1), adj2(m+1);

         for(auto it:edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
         }
         for(auto it:edges2) {
            adj2[it[1]].push_back(it[0]);
            adj2[it[0]].push_back(it[1]);  
         } 

         int d1=0 ;
         int dummy= diameter(0,adj1,vis1,d1);
         int d2=0;
         int dummy2= diameter(0,adj2,vis2,d2);

        //  cout<<d1<<" "<<d2<<endl;

         int ans = (ceil(double(d1)/2) + ceil(double(d2)/2) + 1);
         ans = max (ans, max(d1,d2));

         return ans;
    }
};