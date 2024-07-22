class Solution {
public:
    bool isvalid(int x,int y, int n,int m,vector<vector<int>>& vis) {
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //bfs on 2d grid
        int n=grid.size(),m=grid[0].size();

        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};


        vector<vector<int>> vis(n+1,vector<int>(m+1,0));
        int cnt=0;   

        bool flag=true;  

          queue<pair<pair<int,int>,int>> q;   

          for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2 and !vis[i][j]) {
                     q.push({{i,j},flag});
                }
            }
          } 
          int count=0,prev=0;
                   
                 while(q.size()) {
                        int x=q.front().first.first;
                        int y=q.front().first.second;
                        bool findflag=q.front().second;
                        vis[x][y]=1;
                        q.pop();

                        if(count%2==0 and findflag==false) {
                            if(prev) cnt++;
                            prev=0;
                            count++;
                        } else if(count%2 and findflag==true) {
                            count++;
                            if(prev) cnt++;
                            prev=0;
                        }
 

                        bool f=false;

                        for(int i=0;i<4;i++) {
                            int x1=x+dx[i];
                            int y1=y+dy[i];

                            if(isvalid(x1,y1,n,m,vis) and grid[x1][y1]==1) {   
                              vis[x1][y1]=1;
                              q.push({{x1,y1},!findflag});
                              f=true;
                            }
                        }
                        if(f) prev++;
                    }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j]==0 and grid[i][j]==1) return -1;
            }
        }
 
        return cnt;
    }
};