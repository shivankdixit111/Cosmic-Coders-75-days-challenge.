class Solution {
public:
    
    bool isvalid(int x, int y, int n, int m , vector<vector<int>> &vis) {
         if(x<0 or y<0 or x>=n or y>=m or vis[x][y]) return false;
         return true;
    }
    
    void bfs(int i,int j,vector<vector<int>> &vis,int n,int m,vector<vector<char>> &board) {
        queue<pair<int,int>> q;
        q.push({i,j});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};

        while(q.size()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(vis[x][y]) continue;
            vis[x][y]=1;

            for(int k=0;k<4;k++) {
                int x1=x+dx[k];
                int y1=y+dy[k];

                if(isvalid(x1,y1,n,m,vis) and board[x1][y1]=='O') {
                    q.push({x1,y1});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         int n=board.size();
         int m=board[0].size();      
         vector<vector<int>> vis(n+1,vector<int>(m+1,0)) ;

         for(int j=0;j<m;j++) {
            if(!vis[0][j] and board[0][j]=='O') {
                 bfs(0,j,vis,n,m,board);
            }
            if(!vis[n-1][j] and board[n-1][j]=='O') {
                cout<<"YES"<<endl;
                bfs(n-1,j,vis,n,m,board);
            }
         }

         for(int i=0;i<n;i++) {
            
            if(!vis[i][0] and board[i][0]=='O') {
                bfs(i,0,vis,n,m,board);
            }
            if(!vis[i][m-1] and board[i][m-1]=='O') {
                bfs(i,m-1,vis,n,m,board);
            }
         }
         for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] and board[i][j]=='O')  board[i][j]='X';
                // cout<<vis[i][j]<<" ";
            }
            // cout<<endl;
         }

        //  return board;        
    }
};