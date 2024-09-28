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

vector<int> computeZ(const string& s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i <= R) {
                Z[i] = min(R - i + 1, Z[i - L]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > R) {
                L = i;
                R = i + Z[i] - 1;
            }
        }
        return Z;
    }
vector<int> longestCommonPrefix(string &a, string &b) {
    string combined = a + "#" + b;
    vector<int> lps = computeZ(combined);
    return lps;
}

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
       vector<int> pref = longestCommonPrefix(pattern,s);
        reverse(s.begin(),s.end());
        reverse(pattern.begin(),pattern.end());
        vector<int> suff = longestCommonPrefix(pattern,s);
        vector<int> prefix,suffix;
        int n=s.size(),m=pattern.size();
        for(int i=m+1;i<pref.size();i++) prefix.push_back(pref[i]),suffix.push_back(suff[i]);
        reverse(suffix.begin(),suffix.end()); 

        int ans = INT_MAX;
      
        rep(i,0,n) {
            if( i+pattern.length()-1<n and prefix[i] + suffix[i+pattern.length()-1]==pattern.length()-1) {
                ans = min(ans,i);
            }
            
            if(prefix[i]==pattern.length())  {
                ans = min(ans, i); //direct match
            }
        }

        return (ans==INT_MAX ? -1 : ans);
    }
};