#define vi vector<int>
#define ll long long int
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
    long long minNumberOfSeconds(int h, vector<int>& t) {

        sort(t.begin(),t.end());
     

        auto f=[&](int t,ll m) {
           ll low=1,high = 1e5,ans=-1;
           while(low<=high) {
              ll mid = (low+high)>>1;

              ll ch = mid*(mid+1)/2;

            //   cout<<t<<" "<<mid<<" "<<ch<<endl;
              if(ch*t <= m) {
                 ans = mid;
                 low = mid+1;
              } else {
                 high = mid-1;
              }
           }
        //    cout<<ans<<endl;
           return ans;
        };
            ll low=0,high=1e18,ans=-1;
 
        auto check=[&](ll mid) {
            ll time= 0, height=0;
            // mid=12;
            for(auto it: t) {
              ll c = f(it,mid);
              time = max( (c*(c+1)/2)*it ,time);
              height += c;
              if(height>=h) return true;
            //   cout<<f(it,mid)<<" ";
            }
            // cout<<endl;
            // cout<<mid<<" "<<height<<" "<<time<<endl;
           
              return (height>=h);


        };
        

        while(low<=high) {
            ll mid = (low+high)>>1;

            if(check(mid)) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};