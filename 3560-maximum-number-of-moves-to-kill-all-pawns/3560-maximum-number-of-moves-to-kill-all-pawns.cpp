int dist[50][50][50][50];
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};

class Solution {
public:
    void calcdistance(int kx, int ky) {
        queue<pair<pair<int,int>,int>> q;
        q.push({{kx,ky},0});
        dist[kx][ky][kx][ky]=0;
        
        while(q.size()) {
            int d = q.front().second;
            int x = q.front().first.first;
            int y = q.front().first.second;
            q.pop();

            for(int i=0;i<8;i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx>=0 and newx<50 and newy>=0 and newy<50 and dist[kx][ky][newx][newy]==-1) {
                    dist[kx][ky][newx][newy] = 1 + d;
                    q.push({{newx,newy},1+d});
                }
            }
        }
    }

    void precompute() { 
        static bool flag = false; // use of static bool to initialise the flag once
        if(flag) return; // Skip if already preprocessed
        memset(dist,-1,sizeof(dist));
        for(int i=0;i<50;i++) {
            for(int j=0;j<50;j++) {
                if(dist[i][j][i][j]==-1)
                calcdistance(i,j);
            }
        } 
         flag = 1;
    }

    int rec(int curr, vector<vector<int>> &positions, int n, vector<vector<int>> &dp,
    int turn,int mask) { 
        if(mask== (1<<n)-1) return 0; // all positions are visited
        
        if(dp[mask][curr]!=-1) return dp[mask][curr];

        int x= positions[curr][0];
        int y= positions[curr][1];

        int ans;

        if(turn==0) {
            //alice
             ans = INT_MIN;
            for(int i=0;i<n;i++) {
                if( mask & (1<<i)) continue;
                int newx= positions[i][0];
                int newy= positions[i][1];  
                ans = max(ans, dist[x][y][newx][newy] + rec(i,positions,n,dp,!turn,mask|(1<<i)));
            } 
        } else {
            // bob
             ans = INT_MAX;
            for(int i=0;i<n;i++) {
                if( mask & (1<<i) ) continue;
                int newx= positions[i][0];
                int newy= positions[i][1];
                
                ans = min(ans, dist[x][y][newx][newy] + rec(i,positions,n,dp,!turn,mask|(1<<i)));
            } 
        } 
        return dp[mask][curr]=ans;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx,ky});
         int n= positions.size();
          precompute();
        vector<vector<int>> dp(1<<n,vector<int>(n,-1));
        int ans =  rec(n-1,positions,n,dp,0,1<<(n-1)); // mask = 1<<(n-1) bcoz horse is taken

        return ans;
    }
};