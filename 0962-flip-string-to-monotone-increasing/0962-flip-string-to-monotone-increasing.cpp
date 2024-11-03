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
    vvii dp;
    int rec(int i,bool zero,string &s) {
        if(i<0) return 0;

        if(dp[i][zero]!=-1) return dp[i][zero];
        
        int ans = INT_MAX;
        if(zero) {
            ans = (s[i]=='1') + rec(i-1,zero,s);
        } else {
           if(s[i]=='0') { 
              ans = min(rec(i-1,true,s),1 + rec(i-1,zero,s));
           } else {
              ans = min(rec(i-1,zero,s), 1 + rec(i-1,true,s));
           }
        }
        return dp[i][zero] = ans;
    }
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        dp.resize(n+1,vi(2,-1));
        return rec(n-1,0,s);
    }
};