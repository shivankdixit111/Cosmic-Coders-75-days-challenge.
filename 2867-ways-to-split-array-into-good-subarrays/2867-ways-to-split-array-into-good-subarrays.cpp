

// lc
#define vi vector<int>
#define vvii vector<vi>
#define ll long long int
#define pii pair<int,int>
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

const int mod = 1e9+7;
class Solution {
public:
    vvii dp;
    int rec(int i, int flag, vi &nums) {
        if(i==nums.size()) return (int)(flag);
        if(dp[i][flag] != -1) return dp[i][flag];
        int ans = 0;
        if(flag) {
            if(nums[i]==0) {
                ans = (rec(i+1,0,nums)%mod + rec(i+1,1,nums)%mod)%mod;
            } else {
                ans = rec(i+1,1,nums)%mod;
            }
        } else {
            if(nums[i]==1) flag = 1;
            ans = rec(i+1,flag,nums)%mod;
        }
        return dp[i][flag] = ans;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size(),start=-1,end=-1, zeroes=0,ans=1; 
        // for(int i=0;i<n;i++) {
        //     if(nums[i]==1) {
        //         start = i;
        //         break;
        //     }
        // }
        // for(int i=n-1;i>=0;i--) if(nums[i]==1) {end =i; break;}
        // if(start==-1 and end==-1) return 0;
        // if(start==-1 or end==-1) return 1;
        // for(int i=start;i<=end;i++) {
        //     if(nums[i]==0) zeroes++;
        //     else {
        //         ans = (ans %mod *1LL*(zeroes+1)%mod)%mod;
        //         zeroes=0;
        //     }
        // }
        // return ans;
        dp.resize(n+1,vi(2,-1));
        return rec(0,0,nums);
    }
};