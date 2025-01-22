#define vi vector<ll>
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
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vvii>> dp(101,vector<vvii>(22,vvii(target+2,vi(2,-1))));
        auto rec = [&](int i, int prevColor, int neighbours, int canColor, auto &&self)->int{ 
             if(neighbours > target) return 1e9;
             if(i==m) {
                if(neighbours == target) return 0;
                return 1e9;
             }
            if(dp[i][prevColor+1][neighbours][canColor] != -1) { 
                return dp[i][prevColor+1][neighbours][canColor];
            }
             int ans = 1e9; 
             if(houses[i]>0) { 
                ans = self(i+1, houses[i], ((houses[i]==prevColor) ? neighbours : neighbours+1), 0, self);
             } else {
                rep(j,1,n+1){
                    if(prevColor != j) {
                        ans = min(ans, cost[i][j-1] + self(i+1, j, neighbours+1, 1, self));
                    } else {
                        ans = min(ans, cost[i][j-1] + self(i+1, j, neighbours, 1, self));
                    }
                }
             }
             return dp[i][prevColor+1][neighbours][canColor] = ans;
        };
        int ans = rec(0,-1,0,0,rec);
        if(ans >=1e9) return -1;
        return ans;
    }
};