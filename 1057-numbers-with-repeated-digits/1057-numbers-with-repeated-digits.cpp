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
    string s;
    vector<vector<vector<vvii>>> dp;
    int rec(int i, int mask, int dup, int started, int prefixMatch, int n){  
        if(i==s.length()){
            if(dup) return 1;
            return 0;
        }

        if(dp[i][mask][dup][started][prefixMatch] != -1) {
            return dp[i][mask][dup][started][prefixMatch];
        }
 
        int ans = 0; 
        char limit = (prefixMatch) ? s[i] : '9';
        for(int j=0;j<=9;j++) {
            char ch = char(j + '0');
            if(ch <= limit) {
                int dupP = ((mask & (1<<j)) | dup) ? 1 : 0; 
                int tempMask = mask; 
                if(j==0) {
                    if(mask!=0){
                        tempMask |= (1<<j);
                    }
                } else {
                    tempMask |= (1<<j);
                } 
                ans += rec(i+1, tempMask, dupP, 1, (prefixMatch & (s[i]==ch)), n);
            }
        } 
        return dp[i][mask][dup][started][prefixMatch] = ans;
    }
    int numDupDigitsAtMostN(int n){
        s = to_string(n);
        int n1 = s.length();
        dp.resize(10, vector<vector<vvii>>((1024), vector<vvii>(2, vvii(2,vi(2,-1))))); 

        return rec(0,0,0,0,1,n);
    }
};
