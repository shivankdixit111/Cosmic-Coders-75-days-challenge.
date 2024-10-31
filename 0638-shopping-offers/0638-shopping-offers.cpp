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
    bool isapplicable(vi &mp, vi &arr) {
         rep(i,0,arr.size()-1) {
            if(mp[i]<arr[i])   return false;
         }
         return true;
    } 
    map<int,map<vector<int>,int>> dp;
    int rec(int i,vector<int>& price, vector<vector<int>>& special, vector<int>& needs, vi mp) {
        if(i==special.size()) {
            int s=0;
            rep(j,0,price.size()) {  
                s += price[j]*mp[j];
            } 
            return s;
        } 
        if(dp.find(i)!=dp.end() and dp[i].find(mp)!=dp[i].end()) return dp[i][mp];

        int take=INT_MAX , nottake=INT_MAX;
            vi arr = special[i];
            if(isapplicable(mp,arr)) { 
                rep(j,0,arr.size()-1)  { 
                    mp[j] = mp[j]-arr[j];
                }

               take = arr[arr.size()-1] + rec(i,price,special, needs, mp);

               rep(j,0,arr.size()-1)  
                    mp[j] = mp[j]+arr[j];
            } 

            nottake = rec(i+1,price,special, needs, mp);
 
            return dp[i][mp] = min(take,nottake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vi mp(price.size(),0);
         rep(i,0,needs.size()) mp[i] = needs[i]; 

        int ans =  rec(0,price, special, needs, mp);
        dp.clear();
        return ans;
    }
};