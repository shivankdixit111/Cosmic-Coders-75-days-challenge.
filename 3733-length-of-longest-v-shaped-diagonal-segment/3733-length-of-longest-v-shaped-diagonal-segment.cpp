// lc
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define pii  pair<int,int>
#define ll long long int
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end());
const int mod = 1e9 + 7;

class Solution {
public:
    
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int dx[4] = {-1, -1, 1, 1}; //tl. tr.  bl br
        int dy[4] = {-1, 1, -1, 1}; //tr br bl tl
        int n = grid.size(), m = grid[0].size();
        map<int,int> d;
        d[0] = 1, d[1] = 3, d[2] = 0, d[3] = 2;
        
        int dp[501][501][5][2];
        rep(i,0,n) rep(j,0,m) rep(dir,0,5) rep(take,0,2) dp[i][j][dir][take] = -1;

        auto rec = [&](int i, int j, int dir, int taken, auto &&self)->int{ 
            if(dp[i][j][dir+1][taken] != -1) return dp[i][j][dir+1][taken];
            int ans = 0;
            if(dir==-1) {
                rep(k,0,4) {
                    int ii = i + dx[k], jj = j + dy[k];
                    if(ii>=0 and ii<n and jj>=0 and jj<m) {
                        if(grid[ii][jj]==2) {
                            ans = max(ans, 1 + self(ii, jj, k, taken, self));
                        }
                    }
                }
                return ans;
            }
            int ii = i + dx[dir], jj = j + dy[dir];
            if(ii>=0 and ii<n and jj>=0 and jj<m) {
                if((grid[i][j]==2 and grid[ii][jj]==0) or (grid[i][j]==0 and grid[ii][jj]==2)) {
                    ans = max(ans, 1 + self(ii, jj, dir, taken, self));
                }
            }
            if(!taken) {
              int direction = d[dir];
              ii = i + dx[direction];
              jj = j + dy[direction];
              if(ii>=0 and ii<n and jj>=0 and jj<m) {
               if((grid[i][j]==2 and grid[ii][jj]==0) or (grid[i][j]==0 and grid[ii][jj]==2)) { 
                     ans = max(ans, 1 + self(ii, jj, direction, true, self));
                }
              }
            }
            return dp[i][j][dir+1][taken] = ans;
        };
        
        vpii ones;
        int ans = 0;
        rep(i,0,n) {
            rep(j,0,m)  {
                if(grid[i][j]==1) ans = max(ans, 1 + rec(i, j, -1, 0, rec));
            }
        }
             
        // int ans = 0;
        // vvii dist(n,vi(m,0));
        // for(auto it: ones) {
        //     // cout<<it.ff<<" "<<it.ss<<" "<<1 + rec(it.ff, it.ss, -1, 0, rec)<<endl;
        //     // cout<<it.ff<<" "<<it.ss<<" "<<grid[it.ff][it.ss]<<endl;
        //     priority_queue<vi> pq;
        //     pq.push({it.ff, it.ss, -1, 0});
        //     dist[it.ff][it.ss] = 1;
        //     while(pq.size()) {
        //         int i = pq.top()[0];
        //         int j = pq.top()[1];
        //         int dir = pq.top()[2];
        //         int taken = pq.top()[3];
        //         pq.pop();
        //         // cout<<i<<" "<<j<<" "<<dir<<" "<<taken<<" dist "<<dist[i][j]<<endl;
                
                
        //         if(dir==-1) {
        //             rep(k,0,4) {
        //                 int ii = i + dx[k];
        //                 int jj = j + dy[k];
        //                 if(ii>=0 and ii<n and jj>=0 and jj<m) {
        //                     if(grid[ii][jj]==2) { 
        //                        if(dist[ii][jj] < 1 + dist[i][j]) {
        //                           // ans = max(ans, 1 + self(ii, jj, k, 1, self));
        //                           dist[ii][jj] = 1 + dist[i][j];
        //                           pq.push({ii, jj, k, 0});
        //                        }
        //                      }
        //                 }
        //              } 
        //              continue;
        //          } 
        //          //tl. tr.  bl br
        //          rep(k,0,4) {
        //              int ii = i + dx[k];
        //              int jj = j + dy[k];
        //              if(ii>=0 and ii<n and jj>=0 and jj<m) {
        //                 if((grid[ii][jj]==2 and (grid[i][j]==0)) or (grid[ii][jj]==0 and grid[i][j]==2)) {
        //                    if(dir!=k and k==d[dir] and  !taken) {
        //                        if(dist[ii][jj] < 1 + dist[i][j]) {
        //                           // ans = max(ans, 1 + self(ii, jj, k, 1, self));
        //                           // cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<" ch dir "<<dir<<" new "<<k<<endl;
        //                           dist[ii][jj] = 1 + dist[i][j];
        //                           pq.push({ii, jj, k, 1});
        //                        }
        //                    }
        //                    if(dir==k) { 
        //                         if(dist[ii][jj] < 1 + dist[i][j]) {
        //                           // ans = max(ans, 1 + self(ii, jj, k, taken, self));
        //                             // cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<" no dir "<<dir<<" new "<<k<<endl;
        //                           dist[ii][jj] = 1 + dist[i][j];
        //                           pq.push({ii, jj, k, taken});
        //                        }
        //                    }
        //                 }
        //              }
        //         } 
        //     }
        // }
        // rep(i,0,n) {
        //     rep(j,0,m)  ans = max(ans, dist[i][j]); 
        // }
        return ans;
        
    }
};