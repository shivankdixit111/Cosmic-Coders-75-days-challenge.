#define ll long long int
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
    long long validSubstringCount(string w, string t) {
        ll ans=0,n=w.length();
        unordered_map<int,int> mp1,mp2;
        for(auto it:t) mp2[it-'a']++;

        auto ok=[&]() {
            rep(i,0,26) {
                if(mp1[i]<mp2[i]) return false;
            }
            return true;
        };
        int i=0,j=0;
        while(j<n) {
            // if(mp2[w[j]-'a']) { 
                    mp1[w[j]-'a']++; 
            // }

            while(ok()) {
                ans += (n-j);
                mp1[w[i]-'a']--;
                i++; 
            }
            j++;
        }
        // cout<<ans<<endl;
        // j=i;
        // cout<<i<<endl;
        // mp1.clear();
        // while(j<n) {
        //     mp1[w[j]-'a']++;
        //     if(ok()) {
        //         cout<<j<<endl;
        //         ans += (n-j);
        //         mp1[w[i]-'a']--;
        //         i++; 
        //     }
        //     j++;
        // }
        return ans;
    }
};