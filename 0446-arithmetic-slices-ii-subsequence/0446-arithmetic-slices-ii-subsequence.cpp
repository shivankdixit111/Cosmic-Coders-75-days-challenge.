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
    
    int rec(int i, long long prev, long long prevdiff, int sz, vi &nums, map<pair<int,pair<int,int>>,int> &mp) {
        if(i==nums.size()) return 0;

        if(mp[{i,{prevdiff,sz}}]) return mp[{i,{prevdiff,sz}}];
        
        int ans=0;
        rep(j,i,nums.size()) { 
            if(sz==1) {
               ans += rec(j, nums[j], 0, sz+1, nums, mp);
            }
            if(sz==2 and i<j) {
                 ans += rec(j, nums[j], nums[j]-prev, sz+1, nums, mp);
            } 
            if(sz>=3 and i<j) {
               long long currdiff = nums[j] - prev;
               if( currdiff == prevdiff ) {  
                  ans += 1 + rec(j, nums[j], nums[j]-prev, sz+1, nums, mp);
               }
            }
        }
        return mp[{i,{prevdiff,sz}}] = ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,pair<int,int>>,int> mp;
        return rec(0,0LL,0LL,1,nums,mp);
    }
};