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
    bool rec(int mask,vi &total, vi &dp, vi &nums, int sum) {
        int n = nums.size();
        if(mask==(1<<n)-1) return true;

        if(dp[mask]!=-1) return dp[mask];
        
        bool ans = false;
        rep(j,0,nums.size()) {
            if(!((1<<j)&mask)) {
                if(total[mask]%sum + nums[j] <= sum) {
                    total[(1<<j)|mask] = total[mask] + nums[j];
                    ans = ans | rec((1<<j)|mask, total, dp, nums, sum);
                }  
            }
        }
        return dp[mask] = ans; 
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         int sum = SUM(nums);
         int n = nums.size();
         if(sum%k) return false;
         vi dp((1<<n),-1),total((1<<n),0);
         sum = sum/k;
         return rec(0,total,dp,nums,sum);
    }
};