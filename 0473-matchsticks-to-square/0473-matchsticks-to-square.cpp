
// lc
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
#define rev(a) reverse(a.begin(), a.end());

class Solution {
public:
    int sum;
    ll a1,a2,a3,a4;
    map<int,int> dp;
    int rec(int i, vi &arr) {
        if(i==arr.size())  {
              if(a1==0 and a2==0 and a3==0 and a4==0) return true;
              return false;
        }

        // cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;

        // if(dp.count(i)) return dp[i];

        bool ans = false;

        if(a1>=arr[i]) {
            a1 -= arr[i];
            if(rec(i+1,arr)) return true;
            a1 += arr[i];
        }
         if(a2>=arr[i]) {
            a2 -= arr[i];
            if(rec(i+1,arr)) return true;
            a2 += arr[i];
        }
         if(a3>=arr[i]) {
            a3 -= arr[i];
            if(rec(i+1,arr)) return true;
            a3 += arr[i];
        }
         if(a4>=arr[i]) {
            a4 -= arr[i];
            if(rec(i+1,arr)) return true;
            a4 += arr[i];
        }


        return  ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        sum = SUM(matchsticks);
         if(sum%4) return false;
         rall(matchsticks);
        //  dp.resize(100,-1);
        a1=sum/4,a2=sum/4,a3=sum/4,a4=sum/4;
         int ans = rec(0,matchsticks); 
        //  rep(i,0,20) {
        //     cout<<dp[i]<<" ";
        //  }
        //  cout<<endl;
         return ans;
    }
};