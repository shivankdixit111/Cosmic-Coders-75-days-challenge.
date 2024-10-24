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
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = MAX(nums), high = SUM(nums) , ans=-1;
        auto check = [&](int mid) {
             int cnt=1,sum=0;
             for(int i=0;i<n;i++) { 
                 if(sum + nums[i] <= mid) {
                    sum += nums[i];
                 } else {
                    sum = nums[i];
                    cnt++;
                 }
             }
             return cnt<=k;
        };

        while(low<=high) {
            int mid = (low+high)>>1;

            if(check(mid)) { 
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};