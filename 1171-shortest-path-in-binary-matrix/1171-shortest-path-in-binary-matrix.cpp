class Solution {
public:
    bool isvalid(int x,int y,int n,int m) {
        if(x<0 or y<0 or x>=n or y>=m) return false;
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dx[]={-1,0,1};
        int dy[]={-1,0,1};
        vector<vector<int>> dist(n+1,vector<int>(m+1,1e9));
        queue<pair<int,int>> q;
        if(grid[0][0]==0) {
            q.push({0,0});
            dist[0][0]=1;
        }
        while(q.size()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            if(x==n-1 and y==m-1) break;

            for(int i=0;i<3;i++) {
                for(int  j=0;j<3;j++) {
                    int x1 = x+dx[i];
                    int y1 = y+dy[j];
                    if(isvalid(x1,y1,n,m) and grid[x1][y1]==0 and (1+dist[x][y]<dist[x1][y1]))  {
                        dist[x1][y1]=1+dist[x][y];
                        q.push({x1,y1});
                    }
                }
            }
        }
        return (dist[n-1][m-1]==1e9)?-1:dist[n-1][m-1];
    }
};