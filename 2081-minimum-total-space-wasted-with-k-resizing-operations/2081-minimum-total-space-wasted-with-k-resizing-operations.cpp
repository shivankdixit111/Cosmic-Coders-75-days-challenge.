#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define pii  pair<int,int>
#define ll long long int
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int> 
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
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n = nums.size();  k++;
        vvii dp(n+1,vi(k+1,-1));

        auto rec = [&](int i, int cnt, auto &&self)->int{ 
             if(i==n) { 
                if(cnt<=k) return 0;
                return 1e9;
             } 
             if(cnt>k) return 1e8;
             if(dp[i][cnt] != -1) return dp[i][cnt];

             int ans = INT_MAX,maxi = INT_MIN,sum=0; 
             for(int j=i;j<n;j++) {
                maxi = max(maxi, nums[j]);
                sum += nums[j];
                ans = min(ans, maxi * (j-i+1) - sum + self(j+1, cnt+1, self));
             } 
             
             return dp[i][cnt] = ans;
             
        };

        return rec(0,0,rec);
    }
};