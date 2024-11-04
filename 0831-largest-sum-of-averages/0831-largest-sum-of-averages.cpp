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
    map<pair<int,int>,double> mp;
    double rec(int i,int k1,int k, vi &nums, vi &psum) {
        if(i==nums.size()) {
            return 0;
        }
        if(k1==k) return -1e6;

        if(mp.count({i,k1})) { 
            return mp[{i,k1}]; 
        }

        double ans = 0;
        for(int j=((i==-1)?0:i);j<nums.size();j++) {
            if(i==-1) ans = max(ans, (double)(psum[j])/(j+1) + rec(j+1,k1+1,k,nums,psum));
            else  { 
               ans = max(ans, (double)(psum[j] - psum[i-1])/(j-i+1)+ rec(j+1,k1+1,k,nums,psum));
            }
        }
        
        return mp[{i,k1}] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
           int n = nums.size();
           vi psum(n,0);
           psum[0] = nums[0];
           rep(i,1,n) psum[i] = psum[i-1] + nums[i];
           double ans = rec(-1,0,k,nums,psum);
           mp.clear();
           return ans;

    }
};