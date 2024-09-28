#define vi vector<int>
#define ll long long int
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


class Solution {
public:
    long long maximumTotalSum(vector<int>& arr) {
        ll low=0,high= 1e9,ans=-1;
        sall(arr);

        int n =arr.size();
 
        set<int> st;
        umii mp,taken;
        ll sum=0;
        rep(i,0,n) { 
              int val = mp[arr[i]];
              

              if(val==0) val = arr[i];
              sum += val;
            //   cout<<val<<" ";
                         if(st.count(val)) return -1;
              st.insert(val);

              if(mp[val-1]) {
                mp[arr[i]] = mp[val-1];
              }
              else {
                mp[arr[i]] = val-1; 
              }
 
              taken[val] = 1;
        }
       return sum;
    }
};