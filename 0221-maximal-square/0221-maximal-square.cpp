
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
    int find2dSum(int x1,int y1,int x2,int y2, vvii &psum) {
         int sum = psum[x2][y2]  - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
         return sum;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vvii psum(n+1,vi(m+1,0));
        rep(i,1,n+1) {
            rep(j,1,m+1) {
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + (matrix[i-1][j-1]=='1'?1:0) ;
                // cout<<psum[i][j]<<" ";
            }
            // cout<<endl;
        }
        

        int maxi = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int i1=i, j1=j;
                while(j1<m and i1<n) {
                    int sum = find2dSum(i+1,j+1,i1+1,j1+1,psum);
                    if((i1-i+1)*(j1-j+1) == sum) {
                        maxi = max(maxi,sum);
                    }
                    i1++; j1++;
                }
            }
        }
        return maxi;
    }
};