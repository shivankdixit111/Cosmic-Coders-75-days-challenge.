// lc
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int, int>
#define umii unordered_map<long long, long long>
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
    umii dp;
    long long rec(long long n) {
        if(n==1) return 0;
        if(n<0) return 1e4;

        if(dp[n]) return dp[n];

        long long ans =0;
        if(n&1) {
            ans = min(1 + rec(n-1), 1 + rec(n+1));
        } else {
            ans = 1 + rec(n/2);
        }
        return dp[n] = ans;
    }
    int integerReplacement(int n) {
        return rec(n);
    }
};