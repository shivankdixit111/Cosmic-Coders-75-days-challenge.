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
    int n,m;
    int dfs(int i,int j, vvii &matrix, vvii &dp){ 
        if(dp[i][j] != -1) return dp[i][j];

        int top=1,bottom=1,left=1,right=1; // element is itself has one increasing value
        
        //top
        if(i>0 and matrix[i-1][j] > matrix[i][j]) top = 1 + dfs(i-1,j,matrix,dp);
        //bottom
        if(i<n-1 and matrix[i+1][j] > matrix[i][j]) bottom = 1 + dfs(i+1,j,matrix,dp);
        //left
        if(j>0 and matrix[i][j-1] > matrix[i][j]) left = 1 + dfs(i,j-1,matrix,dp);
        //right
        if(j<m-1 and matrix[i][j+1] > matrix[i][j]) right = 1 + dfs(i,j+1,matrix,dp);

        return dp[i][j] =  max(max(top,bottom), max(left,right));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         n= matrix.size();
         m = matrix[0].size();

        vvii dp(n+1,vi(m+1,-1));
        int maxi = INT_MIN;

        rep(i,0,n) {
            rep(j,0,m) {
                maxi = max(maxi,dfs(i,j,matrix,dp));
            }
        }
        return maxi;
    }
};