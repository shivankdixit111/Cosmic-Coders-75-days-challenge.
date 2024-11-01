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
    int countSubstrings(string s) {
        int n = s.length(),cnt=0;
        vvii pal(n+1,vi(n+1,0));

        for(int i=n-1;i>=0;i--) {
            pal[i][i] = 1;
            cnt++;
            for(int j=i+1;j<n;j++) {
                // we add a character before start and after the end. If previously was 
                // a palindrome and both characters are same then it is still a palindrome
                pal[i][j] = (pal[i+1][j-1] or (j-i==1)) and (s[i]==s[j]);
                cnt += pal[i][j];
            }
        }
        
        return cnt;
    }
};