class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n+1];
        for(auto  it:edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>> matrix(n+1,vector<int>(n+1,1e9));
        
        for(int i=0;i<n;i++) {
            for(auto it:adj[i]) {
                int v=it.first;
                int wt=it.second;
                matrix[i][v]=wt;  
            }
        } 

        //applying floyd warshall
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i==j) continue;
                    matrix[i][j] = min( matrix[i][j] , matrix[i][k] + matrix[k][j] );
                }
            }
        }
        int mini=INT_MAX,ans=-1; 
        
        for(int i=0;i<n;i++) {
            int cnt=0;
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<=distanceThreshold) {
                    cnt++;
                }
            }
            if(mini>=cnt) {
                mini=cnt;
                ans=i;
            }
            // cout<<i<<" "<<cnt<<endl;
        }
        return ans;
    }
};