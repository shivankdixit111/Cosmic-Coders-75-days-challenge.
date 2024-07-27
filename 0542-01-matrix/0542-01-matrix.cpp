class Solution {
public:
    bool isvalid(int x,int y, int n,int m , vector<vector<int>> &vis) {
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<n;i++) {
           for(int j=0;j<m;j++) {
              if(mat[i][j]==0) {
                 q.push({{i,j},0});
                 vis[i][j]=1;
              }
           }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        while(q.size()) {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            mat[x][y]=dist;

            for(int k=0;k<4;k++) {
                int x1=x+dx[k];
                int y1=y+dy[k];

                if(isvalid(x1,y1,n,m,vis)) {
                    q.push({{x1,y1},dist+1});
                    vis[x1][y1]=1;
                }
            }
        }
        return mat;
    }
};