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
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sall(nums);
        set<int> st;
        rep(i,0,n){
            int low = nums[i] - k;
            int high = nums[i] + k;
            if(st.empty()) {
                st.insert(low);
            } else {
                int larg = *(st.rbegin());
                if(low > larg) st.insert(low);
                else if(larg + 1 <= high) st.insert(larg + 1);
            }
        }
        return st.size();
    }
};