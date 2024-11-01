
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
    map<pair<pair<int,int>,int>,int> dp;
    int rec(int i,int c0,int c1, int n, int m, vpii &arr) { 
        if(i==arr.size()) return 0;

        if(dp.count({{i,c0},c1})) return dp[{{i,c0},c1}];
        
        int ans = 0;
        if(c0+arr[i].first<=m and c1+arr[i].ss<=n) {
           ans = 1 + rec(i+1, c0+arr[i].ff, c1+arr[i].ss, n, m, arr);
        }
        ans = max(ans, rec(i+1, c0, c1, n, m, arr));
        return dp[{{i,c0},c1}] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vpii arr;
        for(auto s:strs) {
            int c0=0,c1=0;
            for(auto it:s) {
                if(it=='0') c0++;
                else c1++;
            }
            arr.push_back({c0,c1});
        }
        return rec(0,0,0,n,m,arr);
        
    }
}; 