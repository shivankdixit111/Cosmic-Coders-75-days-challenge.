
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define minpq(a) priority_queue<a,vi,greater<a>> pq
#define maxpq(a) priority_queue<a> pq 
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
#define N 1e5+1

class Solution {
public:
    umii mp;
    vvii dp;
    int n,m;
    int rec(int i,int j,string &s,string &t) {
        if(i==n) {
            if(j==m) return 0;
            return -1e9;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = rec(i+1,j,s,t);
        if(mp.count(i)) {
            ans = max(ans, 1 + rec(i+1,j,s,t));
        }
        if(s[i]==t[j]) {
            ans = max(ans,rec(i+1,j+1,s,t));
        }
        
        return dp[i][j] = ans;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        n = source.size();
        m = pattern.size();

        for(auto it:targetIndices) mp[it]++;

        dp.resize(n+1,vi(m+1,-1));
        // dp[0][0]=0;

        return rec(0,0,source,pattern);

        // for(int i=1;i<=n;i++) {
        //     for(int j=1;j<=m;j++) {
        //         dp[i][j] =  dp[i-1][j];
        //         if(mp.count(i-1)) dp[i][j] = max(dp[i][j],1 + dp[i-1][j]);
        //         if(source[i-1]==pattern[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
        //     }
        // }

        // return dp[n][m];
         
    }
};