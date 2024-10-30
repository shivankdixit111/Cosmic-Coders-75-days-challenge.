#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define pii pair<int,int>
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
    vi dp;
    int rec(int i,int end, vvii &intervals) {
        if(i==intervals.size()) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int take =0,nottake=0;
        if(intervals[i][0] >= end ) {
            take = 1 + rec(i+1,intervals[i][1],intervals);
        }
        nottake = rec(i+1,end,intervals);
        
        return  dp[i] = max(take,nottake);
    }
    static bool cmp(vi &a, vi &b){ 
          return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        
        sort(intervals.begin(),intervals.end(),cmp);
        dp.resize(n+1,-1);
        
        int ans = intervals.size() - rec(0,INT_MIN,intervals);
        return ans;
    }
};