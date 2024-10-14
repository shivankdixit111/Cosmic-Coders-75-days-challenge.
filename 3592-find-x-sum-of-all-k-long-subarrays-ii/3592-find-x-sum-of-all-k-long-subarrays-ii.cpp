#define ll long long int
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
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        set<pair<ll,ll>> s1,s2;
        unordered_map<ll,ll> f;
        vector<ll> ans; 
        ll sum=0;

        auto fix=[&]() {
             if(s1.size()>x) {
                auto it = *s1.begin();
                s1.erase(it);
                s2.insert(it);
                sum-= it.ff*it.ss;
             }

             while( s1.size() and s2.size() ) {
                auto it2 = *(--s2.end());
                auto it1 = *(s1.begin());

                if( it1 < it2 ) {
                    s2.erase(it2);
                    s1.erase(it1);
                    s2.insert(it1);
                    s1.insert(it2);

                    sum -= it1.ff * it1.ss;
                    sum += it2.ff * it2.ss;
                } else {
                    break;
                }
             }
        };

        auto add=[&](int x) {
             if(s1.find({f[x],x})!=s1.end()) {
                sum -= f[x]*x;
             }
             s1.erase({f[x],x});
             s2.erase({f[x],x});
             f[x]++;
             s1.insert({f[x],x});
             sum += f[x]*x;

             fix();
        };

         auto era=[&](int x) {
             if(s1.find({f[x],x})!=s1.end()) {
                sum -= f[x]*x;
             }
             s1.erase({f[x],x});
             s2.erase({f[x],x});
             f[x]--;
             s1.insert({f[x],x});
             sum += f[x]*x;

             fix();
        };


        rep(i,0,k) {
            add(nums[i]); 
        }

        ans.push_back(sum);

        rep(i,k,n) {
            add(nums[i]);
            era(nums[i-k]);
            ans.push_back(sum);
        }
        return ans;
    }
};