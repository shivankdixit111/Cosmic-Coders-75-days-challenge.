

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
    int ans;
    void rec(int x1,int x2,int x3, int cnt, int n) {
            // cout<<x1<<" "<<x2<<" "<<x3<<" "<<cnt<<endl;
        if(cnt==n) {
            ans = min(min(x1,x2),x3);
            return;
        }

        int mini = min(min(x1,x2),x3);
        rec( x1*(x1==mini?2:0), x2+(x2==mini?3:0), x3+(x3==mini?5:0), cnt+1,n); 
    }

    int nthUglyNumber(int n) {
        // if(n==1) return 1;
        //  rec(2,3,5,2,n);
        //  return ans;
        umii mp;
        priority_queue<long long,vector<long long>,greater<>> pq;
        int cnt=1;
        pq.push(1);

        while(true) {
           long long x= pq.top();
           pq.pop();

           if(cnt==n) {
              return x;
           }

           if(mp[x*2]==0) pq.push(x*2),mp[x*2]=1;
           if(mp[x*3]==0) pq.push(x*3),mp[x*3]=1;
           if(mp[x*5]==0) pq.push(x*5),mp[x*5]=1;

           cnt++;
        }
        return 0;
    }
};