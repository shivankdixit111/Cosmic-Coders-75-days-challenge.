// lc
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
#define rev(a) reverse(a.begin(), a.end());

class Solution {
public:  
    bool rec(int i,int prev, int n, vi &stones, umii &mp, vvii &dp) {
         if(i==n-1) return true;

         if(dp[i][prev]!=-1) return dp[i][prev];
         
         bool ans = false;
         if(prev and mp[stones[i]+prev-1] and mp[stones[i]+prev-1] > mp[stones[i]]) ans = rec(mp[stones[i]+prev-1],prev-1,n,stones,mp,dp);
         if(mp[stones[i]+prev] and mp[stones[i]+prev] > mp[stones[i]]) ans = ans | rec(mp[stones[i]+prev],prev,n,stones,mp,dp);
         if(mp[stones[i]+prev+1]) ans = ans | rec(mp[stones[i]+prev+1],prev+1,n,stones,mp,dp);

         return dp[i][prev] = ans;
         
    }
    bool canCross(vector<int>& stones) {
         int n = stones.size();
         umii mp;
         vvii  dp(n+1,vi(2001,-1));
         rep(i,0,stones.size()) mp[stones[i]] = i;
         return rec(0,0,n,stones,mp,dp);
    }
};