
// lc
#define vi vector<int>
#define vvii vector<vi>
#define ll long long int
#define pii pair<int,int>
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
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int sum = 0,sum1=0,sum2=0;
        rep(i,0,n) {
            rep(j,0,n) { 
               if(i==j) sum += fruits[i][j];  //top left
            } 
        }
        vvii dp(n+1,vi(n+1,-1));
        auto rec1 = [&](int i, int j, auto &&self)->int{
            // cout<<i<<" "<<j<<endl;
             if(i==n or j==n or i<0 or j<0) return 0;
             if(i>=j) return 0;
             if(dp[i][j] != -1) return dp[i][j];
             int ans = 0;
             ans = fruits[i][j] + self(i+1,j+1,self);
             ans = max(ans, fruits[i][j] + self(i+1,j-1,self));
             ans = max(ans, fruits[i][j] + self(i+1,j,self));

             return dp[i][j] = ans;
        };
        // 0 n-1
        sum1 = rec1(0,n-1,rec1);

        auto rec2 = [&](int i, int j, auto &&self)->int{
             if(i==n or j==n or i<0 or j<0) return 0;
             if(i<=j) return 0;
              if(dp[i][j] != -1) return dp[i][j];
             int ans = 0;
             ans = fruits[i][j] + self(i+1,j+1,self);
             ans = max(ans, fruits[i][j] + self(i-1,j+1,self));
             ans = max(ans, fruits[i][j] + self(i,j+1,self));

             return dp[i][j] = ans;
        };
        rep(i,0,n) rep(j,0,n) dp[i][j] = -1;
        // n-1 0
        sum2 = rec2(n-1,0,rec2);
 

        return sum + sum1 + sum2;
    }
};