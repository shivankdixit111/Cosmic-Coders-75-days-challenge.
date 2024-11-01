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
    int rec(int i,int prev, vvii &pairs) {
        if(i==pairs.size()) return 1;
          int take = -1e6,nottake=-1e6;
         if(prev==-1) {
           take = max(take,max(rec(i,i,pairs),rec(i+1,prev,pairs)));
           return take;
        }

        if(dp[i][prev]!=-1) return dp[i][prev];
        
      
       
        if(pairs[prev][1] < pairs[i][0]) {
            take = 1 + rec(i+1,i,pairs);
        }
        nottake = rec(i+1,prev,pairs);
       
        return dp[i][prev] = max(take,nottake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        umii mp;
        int ans = INT_MIN, n= pairs.size();
        sort(pairs.begin(),pairs.end(),[&](vi &a, vi &b){
             return a[0]<b[0];
        });    
        dp.resize(n+1,vi(n+1,-1));
        return  rec(0,-1,pairs);
    }
};