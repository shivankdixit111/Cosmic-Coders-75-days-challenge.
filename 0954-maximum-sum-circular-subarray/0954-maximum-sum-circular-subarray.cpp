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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int s=0,ans=INT_MIN;
        rep(i,0,n) {
            //kadane algo
            s += nums[i];
            ans = max(ans,s);
            if(s<0) s=0;
        }

        vi maxTill(n,-1e8); 
        s = nums[0];
        maxTill[0] = nums[0];
        rep(i,1,n) {
            s += nums[i]; 
            maxTill[i] = max(maxTill[i-1] ,s);
        } 
 

         s=0;
        for(int i=n-1;i>=1;i--) {
            s += nums[i]; 
            ans = max(ans, maxTill[i-1] + s);
        }
        return ans;
    }
};