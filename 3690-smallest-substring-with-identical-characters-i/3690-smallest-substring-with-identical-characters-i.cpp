#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define pii  pair<int,int>
#define ll long long int
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int> 
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
    int minLength(string s, int numOps) {
        priority_queue<pair<int,pii>> q;
        int n = s.length();

        auto rec = [&](int i, int take, int mid, vvii &dp, auto &&self)->int{
             if(i==n) return 0;
            //  cout<<i<<" "<<take<<" "<<s<<endl;
             if(dp[i][take] != -1) return dp[i][take];
             int ans = 1e6;
                int cnt = 0,j=i;
                while(j<n-1 and s[j]==s[j+1]) {
                    j++; cnt++;
                    if(cnt==mid) { 
                         char ch = s[j];
                         s[j] = (s[j]=='0'?'1':'0'); 
                           ans = min(ans, 1 + self(j, 1, mid, dp, self));
                         s[j] = ch;
                        break; 
                    }
                }
                
                if(cnt!=mid)
                  ans = min(ans, self(i+1, 0, mid, dp, self));
                  
                  //create a substring
                  if(!take) {
                    char ch = s[i];
                    s[i] = (s[i]=='0'?'1':'0');
                    if(mid!=1 or (i==0 or (s[i] != s[i-1]))) 
                     ans = min(ans, 1 + self(i, 1,  mid, dp, self));
                    s[i] = ch; 
                  }

            return dp[i][take] = ans;
        };
       


        int low=1,high=n,len=-1;
        while(low<=high){
            int mid = (low + high)>>1;
            vvii dp(n+1,vi(2,-1));
            int check = rec(0,0,mid,dp,rec);
            cout<<mid<<" "<<check<<endl;
            if(check <= numOps) {
                len = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return len;    
    }
};