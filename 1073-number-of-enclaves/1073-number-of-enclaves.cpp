class Solution {
public:
    bool isvalid(int x,int y, int n,int m , vector<vector<int>> &vis) {
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<int>> &vis,int n,int m,vector<vector<int>> &grid) {
        queue<pair<int,int>> q;
        q.push({i,j});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        while(q.size()) {
            int x=q.front().first;
            int y=q.front().second;  
            q.pop();
             
             if(vis[x][y]) continue;

              vis[x][y]=1;

       
            for(int k=0;k<4;k++) {
                int x1=x+dx[k];
                int y1=y+dy[k];

                if(isvalid(x1,y1,n,m,vis) and grid[x1][y1]==1) {
                    q.push({x1,y1});
                }
            }     
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        

        for(int i=0;i<n;i++) {
            if(!vis[i][0] and grid[i][0]==1) {
                bfs(i,0,vis,n,m,grid);
            } 
            if(!vis[i][m-1] and grid[i][m-1]==1) {
                bfs(i,m-1,vis,n,m,grid);
            }
        }
        for(int j=0;j<m;j++) {
            if(!vis[0][j] and grid[0][j]==1) {
                bfs(0,j,vis,n,m,grid);
            }
            if(!vis[n-1][j] and grid[n-1][j]==1) {
                bfs(n-1,j,vis,n,m,grid);
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 and !vis[i][j]) cnt++;
            }
        }    
        return cnt;
    }
};