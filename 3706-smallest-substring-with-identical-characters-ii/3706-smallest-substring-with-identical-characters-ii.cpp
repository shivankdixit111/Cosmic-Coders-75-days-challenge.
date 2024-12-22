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

        auto check = [&](int mid){
             int i=0,op=0,cnt=1;
             while(i<n) {
                cnt=1;
                while(i<n-1 and s[i]==s[i+1]) {
                    cnt++; 
                    i++;
                }
                if(cnt >= (mid+1)) { 
                    op += cnt/(mid+1);
                }
                i++;
             }
            return op;
        };

        int a=0,b=0;
        rep(i,0,n) {
            if((i&1) == ((s[i]-'0')&1)) a++;
            else b++;
        }
        if(min(a,b) <= numOps) return 1;


        int low=2,high=n,len=-1;
        while(low<=high){
            int mid = (low + high)>>1; 
            int ch = check(mid); 
            cout<<mid<<" "<<ch<<endl;
            if(ch <= numOps) {
                len = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return len;    
    }
};