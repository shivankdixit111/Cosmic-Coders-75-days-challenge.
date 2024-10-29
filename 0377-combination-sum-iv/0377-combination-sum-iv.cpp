// lc
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
    vvii dp;
    int rec(vi &nums, int target,int cnt) { 
        if(target==0) return 1;

        if(dp[target][cnt] != -1) return dp[target][cnt];
        
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<=target) {
                ans += rec(nums,target-nums[i],cnt+1);
            }
        }
        
        return dp[target][cnt] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,vi(target+1,-1));
        return rec(nums,target,0);
    }
};