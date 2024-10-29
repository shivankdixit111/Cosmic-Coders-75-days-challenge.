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
    int rec(int i,bool pos, vi &nums) {
        if(i==nums.size()-1) return 0;
        if(dp[i][pos]!=-1) return dp[i][pos];

        int ans = 0;
        for(int j=i+1;j<nums.size();j++) {
            int diff = nums[j] - nums[i];
            if(pos and diff>0) ans = max(ans, 1 + rec(j,false,nums));
            if(!pos and diff<0) ans = max(ans , 1 + rec(j,true,nums));
        } 
        return dp[i][pos] = ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<int>(2,-1));
        int ans =  max(rec(0,true,nums),rec(0,false,nums))+1; 
        return ans;
    }
};