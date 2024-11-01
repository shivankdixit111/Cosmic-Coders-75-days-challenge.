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
    int rec(int i,int j, vi &nums1, vi &nums2) {
        if(i>=nums1.size() or j>=nums2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(nums1[i]==nums2[j]) {
            dp[i][j] = max(dp[i][j], 1 + rec(i+1,j+1,nums1,nums2));
        } else {
            dp[i][j] = 0;
        }
        int dummy1 = rec(i+1,j,nums1,nums2);
        int dummy2 = rec(i,j+1,nums1,nums2);
        
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        dp.resize(n+1,vi(m+1,-1));
        int a=  rec(0,0,nums1,nums2);
        int maxi = INT_MIN;
        rep(i,0,n) {
            rep(j,0,m) {
               maxi = max(maxi,dp[i][j]);
            }
            // cout<<endl;
        }
        return maxi;
    }
};