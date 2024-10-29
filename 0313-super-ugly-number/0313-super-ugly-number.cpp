
// lc
#define ll long long int
#define vi vector<ll>
#define vvii vector<vi>
#define vpii vector<pair<ll,ll>>
#define vs vector<string>
#define pii pair<ll,ll>
#define mii map<ll, ll>
#define umii unordered_map<ll, ll>
#define minpq(a) priority_queue<a,vector<a>,greater<a>> 
#define maxpq(a) priority_queue<a> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define pb push_back 
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define rev(a) reverse(a.begin(), a.end());

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vi dp(n+1,0);
        vi idx(m+1,0);
        dp[0] = 1;

        rep(i,1,n) {
            ll mini = LONG_MAX;
            for(int j=0;j<m;j++) {
               mini = min(mini, primes[j]*dp[idx[j]]);
            }
            dp[i] = mini;
            
            for(int j=0;j<m;j++) {
                if(mini == primes[j]*1LL*dp[idx[j]]) {
                    idx[j]++;
                }
            }
        }
        return dp[n-1];
    }
};