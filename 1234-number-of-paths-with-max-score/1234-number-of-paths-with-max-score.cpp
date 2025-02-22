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
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(), m = board[0].size();
        vvii dp(n+1,vi(m+1,0));
        map<pair<int,pii>,int> cnt;
        cnt[{1,{1,0}}] = 1;
        
        for(int i=1;i<=n;i++) {
          int count=0;
          for(int j=1;j<=m;j++) {
            char ch = board[i-1][j-1];
            if(ch=='X') {
                count++;
                continue;
            }
            int num = ch-'0';
            if(ch=='E' or ch=='S') num = 0;
 
            dp[i][j] = num + dp[i-1][j];
             if(i>1) cnt[{i,{j, dp[i][j]}}] += cnt[{i-1,{j, dp[i-1][j]}}]%mod;
             cnt[{i,{j, dp[i][j]}}] %= mod;
             dp[i][j] = max(dp[i][j], num + dp[i][j-1]);

             if(num + dp[i][j-1] >= dp[i][j]) {
               dp[i][j] = num + dp[i][j-1];

               if(j>1) cnt[{i,{j, dp[i][j]}}] += cnt[{i,{j-1, dp[i][j-1]}}]%mod;
               cnt[{i,{j, dp[i][j]}}] %= mod;
             }
             if(num + dp[i-1][j-1] >= dp[i][j]) {
              dp[i][j] = num + dp[i-1][j-1];

              if(i>1 and j>1) cnt[{i,{j, dp[i][j]}}] += cnt[{i-1,{j-1, dp[i-1][j-1]}}]%mod;
              cnt[{i,{j, dp[i][j]}}] %= mod;
             }
          }
          if(count==m) {
            return {0,0};
          }
        }

        // for(auto it: cnt) {
        //     pair<int,pii> p = it.ff;
        //     cout<<p.ff<<" "<<p.ss.ff<<" "<<p.ss.ss<<" "<<it.ss<<endl;
        // }
        // cout<<endl;

        int c = cnt[{n,{m, dp[n][m]}}];

        cout<< dp[n][m] <<endl;

        return {dp[n][m], c};
    }
};