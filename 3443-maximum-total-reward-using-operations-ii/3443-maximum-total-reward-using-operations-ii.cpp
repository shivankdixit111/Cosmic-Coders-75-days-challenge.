#define vi vector<int>
#define vs vector<string>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pii pair<int, int>
#define mod1 998244353
#define mci map<char, int>
#define vpii vector<pair<int, int>>
#define vvii vector<vector<int>>
#define mod 1000000007
#define sei set<int>
#define ses set<string>
#define ues unordered_set<string>
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sall(x) sort(x.begin(), x.end());
#define rall(x) sort(x.rbegin(), x.rend())
#define MAX(x) *max_element(x.begin(), x.end())
#define MIN(x) *min_element(x.begin(), x.end())
#define SUM(X) accumulate(X.begin(), X.end(), 0LL)
#define FIND(x, y) binary_search(all(x), y)
#define MEM(x, y) memset(x, y, sizeof(x))
#define binone(x) __builtin_popcountll(x)
#define ll long long int
#define pb push_back
#define Test  \
    ll t;     \
    cin >> t; \
    while (t--)
#define in insert
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repeq(i, a, b) for (int i = a; i <= b; i++)
#define revf(i, a, b) for (int i = b - 1; i >= a; i--)
#define mini(a, b, c) min(a, min(b, c))
#define maxi(a, b, c) max(a, max(b, c))
#define rev(arr) reverse(arr.begin(), arr.end());
const int N = 1e5 + 7;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

vvii ch(2001,vi(10000,-1));

class Solution {
public:
  
    int maxTotalReward(vector<int>& arr) {
        int n=arr.size();
          sall(arr);
         
        
        bitset<100000> mask,bs;
        mask[0]=1;

        int j=0;
        rep(i,0,n) {
            while(j<arr[i]) {
                bs[j]=1;
                j++;
            }
            mask|=((bs&mask)<<arr[i]);
        }
        
        for(int i=100000;i>=0;i--) {
            if(mask[i]==1) return i;
        }
        return 0;
    }

};