#define vi vector<int>
#define vs vector<string>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define pii pair<int,int>
#define mod1 998244353
#define mci map<char,int>
#define vpii vector<pair<int,int>>
#define vvii vector<vector<int>>
#define mod 1000000007
#define sei set<int>
#define ses set<string> 
#define ues unordered_set<string> 
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define sall(x) sort(x.begin(),x.end());
#define rall(x) sort(x.rbegin(),x.rend())
#define MAX(x) *max_element(x.begin(),x.end())
#define MIN(x) *min_element(x.begin(),x.end())
#define SUM(X) accumulate(X.begin(),X.end(),0LL)
#define FIND(x,y) binary_search(all(x),y)
#define MEM(x,y) memset(x,y,sizeof(x))
#define binone(x) __builtin_popcountll(x)
#define ll long long int
#define pb push_back
#define Test ll t;cin>>t;while(t--)
#define in insert
#define ff first 
#define ss second 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define revf(i,a,b) for(int i=b-1;i>=a;i--)
#define mini(a,b,c) min(a,min(b,c))
#define maxi(a,b,c) max(a,max(b,c)) 
#define rev(arr) reverse(arr.begin(),arr.end());
const int N=1e5+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl 
#define endl '\n' //remove for interactives
 
class Solution {
public:
    int rec(int mask,int prev, int n, vi &nums, vvii &dp) {
        if( mask == (1<<n)-1 ) return dp[mask][prev] = abs(prev-nums[0]);

        if(dp[mask][prev]!=-1) return dp[mask][prev];

        int sum=1e9;
        for(int i=0;i<n;i++) {
            if( ! ((1<<i) & mask ))
            sum =  min(sum, abs(prev-nums[i]) + rec( (1<<i)|mask,i, n, nums, dp));
        }
        return dp[mask][prev] = sum;
    }

    void constructperm(int n, vi &perm, vi &nums, vvii &dp) {
        
         for(int prev=0,mask=1 ; perm.size()<n ; mask|=(1<<prev)) {
            for(int curr=0;curr<n;curr++) {
                  if( !((1<<curr) & mask) ) {
                     int currscore = abs(prev-nums[curr]) + dp[mask | (1<<curr)][curr];
                     int minscore = dp[mask][prev];

                     if( minscore == currscore ) {
                        perm.push_back(curr);
                        prev = curr;
                        break;
                     }
                  }
            }
         }
    }

    vector<int> findPermutation(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp( (1<<n) , vector<int>(n,-1));

        int minscore = rec(1,0,n,nums,dp) ; 
        vi perm;
        perm.push_back(0);
        constructperm(n,perm,nums,dp);
        // cout<<minscore<<endl;

        return perm;
    }
};