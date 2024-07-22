class Solution {
public:
    bool isvalid(int x,int y, int n, int m,vector<vector<int>> &vis) {
        if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n=image.size(),m=image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        int col=image[sr][sc];

        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        
        while(q.size()) {
            int x=q.front().first;
            int y=q.front().second;
            vis[x][y]=1;
            q.pop();

            for(int i=0;i<4;i++) {
               int x1=x+dx[i];
               int y1=y+dy[i];

               if(isvalid(x1,y1,n,m,vis) and image[x1][y1]==col) {
                  q.push({x1,y1});
                  image[x1][y1]=color;
               }
            }
            image[x][y]=color;            
        }

        return image;
    }
};