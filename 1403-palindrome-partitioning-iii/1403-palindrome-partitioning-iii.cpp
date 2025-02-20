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
    int palindromePartition(string s, int k) {
        int n = s.length();
        map<pair<int,int>,int> c;
        auto cost = [&](int i, int j){
            int c = 0;
            while(i<=j) {
                if(s[i]!=s[j]) c++;
                i++; j--;
            }
            return c;
        };
        rep(i,0,n) {
            rep(j,i,n) {
                c[{i,j}] = cost(i,j);
            }
        }
     
        vector<vvii> dp(n+1,vvii(n+1,vi(k+1,-1)));
        auto rec = [&](int i, int prev, int k1, auto &&self)->int{
             if(k1>k) return 1e9;
             if(i==n) {
                if(k1==k and prev==n) return 0;
                return 1e9;
             }
             if(dp[i][prev][k1] != -1) return dp[i][prev][k1];
             int ans = 1e9;
             ans = min(ans, c[{prev, i}] + self(i+1, i+1, k1+1, self));
             ans = min(ans, self(i+1, prev, k1, self));
             return dp[i][prev][k1] = ans;
        };
        return rec(0,0,0,rec);
    }
};