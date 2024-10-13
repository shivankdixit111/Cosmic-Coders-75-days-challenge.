

#define vi vector<int>
#define vvii vector<vi>
#define vpii vector<pair<int,int>>
#define vs vector<string>
#define pii pair<int, int>
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
#define SUM(X) accumulate(X.begin(), X.end(), 0)

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         if(nums.size()<k) return {SUM(nums)};
         vi temp;

         int n= nums.size();
         rep(i,0,n) {
            vi freq(55);
            vpii arr;
            if(i+k>n) break;
            rep(j,i,i+k) {
               freq[nums[j]]++;
            }
            rep(i,1,51) if(freq[i]) arr.push_back({freq[i],i});
            sort(all(arr),[&](pii &a,pii &b) {
                 if(a.ff==b.ff) return a.ss>b.ss;
                 return a.ff>b.ff;
            });
            int sum=0;
            for(int i=0;i<min((int)arr.size(),x);i++) sum+=arr[i].ss*arr[i].ff;
            temp.pb(sum);
         }
         return temp;
    }
};