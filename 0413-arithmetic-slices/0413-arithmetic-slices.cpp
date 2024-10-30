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
    map<pair<pii,int>,int> dp;
    int rec(int i,int prev,int prevdiff, int sz, vi &nums) {
        
        if( dp[{{i,prevdiff},sz}] ) return dp[{{i,prevdiff},sz}];

        int ans=0;
        for(int j=i;j<nums.size();j++) {
            if(sz==0) {  //taking all indices 
                ans += rec(j,nums[j],0,sz+1,nums);
            }
            if(sz==1 and i+1==j) {
                ans += rec(j,nums[j],nums[j]-nums[i],sz+1,nums);
            }
            if(sz>=2 and i+1==j) {
                int currdiff = nums[j]-nums[i];
                if(currdiff == prevdiff) {
                    ans = 1 + rec(j,nums[j],nums[j]-nums[i],sz+1,nums);
                }
            }
        }
        return dp[{{i,prevdiff},sz}] = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans =  rec(0,0,0,0,nums); 
        return ans;
    }
};