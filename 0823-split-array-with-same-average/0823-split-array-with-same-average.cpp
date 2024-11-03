
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
    
    bool splitArraySameAverage(vector<int>& nums) {
        int sum = SUM(nums),n=nums.size();
         vector<int> dp(sum+1,0);
         vector<unordered_set<int>> mp(300005);
         dp[0]=1;
         mp[0].insert(0);
         for(auto it:nums) {
            for(int j = sum;j>=it;j--) {
                if(dp[j-it]) {
                    dp[j] = 1;
                    for(auto len:mp[j-it]) {
                        mp[j].insert(len+1);
                         double a1 = (double)(j)/(double)(len+1);
                         double a2 = (double)(sum-j)/(double)(n-(len+1));
                         if(a1==a2) { 
                            return true;
                         }
                    }
                }
            }
         }
       
        //  for(int s = 1;s<=30005;s++) { 
        //     for(auto it:mp[s]) {
        //         if(it==n) continue;
        //          double a1 = (double)(s)/(double)it;
        //          double a2 = (double)(sum-s)/(double)(n-it);
        //          if(a1==a2) return true;
        //     }
        //  }
         return 0;
    }
};