// lc
#define vi vector<int>
#define vs vector<string>
#define mii map<int, int>
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

class Solution {
public:
   string b(int num) {
       string ans="";
        rep(i,0,31) {
            if((1<<i) & num) {
                    ans += '1';
             } else {
                ans+='0';
             }
        }
        // cout<<ans<<endl;
        string s= ans;
        while(s.length() and s[s.length()-1]=='0') s.pop_back();
        reverse(all(s));
        return s;
   }
    string convertDateToBinary(string date) {
       string y = b(stoi(date.substr(0,4)));
       string m = b(stoi(date.substr(5,2)));
       string d = b(stoi(date.substr(8,2)));



       string ans = y+"-"+m+"-"+d;
       return ans;
    }
};