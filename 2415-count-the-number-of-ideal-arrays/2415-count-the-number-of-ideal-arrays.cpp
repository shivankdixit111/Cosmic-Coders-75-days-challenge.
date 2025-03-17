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
    int power(int a, int b) {
        int ans = 1;
        while(b) {
            if(b&1) ans = (ans *1LL* a)%mod;
            b = b>>1;
            a = (a *1LL* a)%mod;
        }
        return ans;
    }
    int idealArrays(int n, int maxValue) {
        int fact[100001];  fact[0] = 1;
        for(int i=1; i<=100000; i++) fact[i] = (fact[i-1] *1LL* i)%mod;
        auto ncr = [&](int n, int r) {
            int dividend = fact[n];
            int divisor = (fact[n-r] *1LL* fact[r])%mod;
            int ans = (dividend *1LL* power(divisor, mod-2))%mod;
            return ans;
        };

        int ans = 0;
        map<pair<int,int>,int> dp;
        auto rec = [&](int val, int idx, auto &&self)->int{
           if(idx==n) return 1;
           if(dp.count({val, idx})) return dp[{val ,idx}];
           int ans = 0,j=2;

        //    ans += self(val, idx+1, self)%mod;   ans %= mod;

           while(val * j <= maxValue) {
              ans += self(val*j, idx+1, self)%mod;   ans %= mod;
              j++;
           }
           if(val * j > maxValue) {
               ans += ncr(n-1, idx-1)%mod; 
           }
            return dp[{val ,idx}] = ans;
        };
        for(int i=1; i<=maxValue; i++) {
            ans += rec(i, 1, rec)%mod;
            ans %= mod;
        }
        return ans;
    }
};