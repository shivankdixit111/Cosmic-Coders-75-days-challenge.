// lc
#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<long, long>
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


class Solution {
public: 
    int rec(int i,int j, vi &arr, mii &mp,vvii &dp) {
        if(i==arr.size() or j==arr.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(i<j and (arr[i]+arr[j]<=(1e9)) and  mp[arr[i]+arr[j]]) {
            dp[i][j] = max(dp[i][j], 1 + rec(j,mp[arr[i]+arr[j]]-1,arr,mp,dp));
        } else {
            dp[i][j] = 0;
        }

        int d1 = rec(i+1,j,arr,mp,dp);
        int d2 = rec(i,j+1,arr,mp,dp);
        return dp[i][j];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size(); 
        rep(i,0,n) st.insert(arr[i]);
        // vvii dp(n+1,vi(n+1,-1));
        // int dummy = rec(0,0,arr,mp,dp);
        // int ans = INT_MIN;

        // rep(i,0,n) {
        //     rep(j,0,n) {
        //         ans = max(ans,dp[i][j]); 
        //     }
        // }
        // mp.clear();
        
        // return (ans?ans+2:ans);
        int ans=0;
        rep(i,0,n) {
            rep(j,i+1,n) {
                int a = arr[i],b=arr[j],c=arr[i]+arr[j],cnt=0;
                while(st.count(c)) {
                    cnt++;
                    a=b;
                    b=c;
                    c=a+b;
                }
                ans = max(ans,cnt);
            }
        }
        return (ans?ans+2:ans);
    }
};