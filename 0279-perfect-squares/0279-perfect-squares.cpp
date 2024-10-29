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
    int rec(int n, vi &dp) {
        //  cout<<n<<" ";
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];
       
        
        int ans = INT_MAX;
        for(int i=1;i<=100;i++) {
            if(i*i<=n) {
                ans = min(ans,1+rec(n-i*i,dp));
            } else {
                break;
            }
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vi dp(n+1,-1);
        return rec(n,dp);
    }
};