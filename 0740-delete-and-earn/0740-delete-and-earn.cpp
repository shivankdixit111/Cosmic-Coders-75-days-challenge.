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
    vi dp;
    int rec(int i, vi &arr) {
        if(i>=arr.size()) return 0;
    
        if(dp[i]!=-1) return dp[i];

        int take=0,nottake=0;
        if(arr[i]>0)
        take = arr[i]*i + rec(i+2,arr);
        nottake = rec(i+1,arr);
        
        return dp[i] = max(take,nottake);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = MAX(nums);
        vi arr(maxi+1,0);
        dp.resize(maxi+1,-1);
        for(auto it: nums) arr[it]++;
        
        return rec(1,arr);

    }
};