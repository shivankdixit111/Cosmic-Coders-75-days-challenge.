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
    int maxGoodNumber(vector<int>& arr) {
        int n = arr.size();
        
        auto fun = [&](vector<int> &idx){
            string temp = "";
             for(int j=0;j<n;j++) {
                string s= "";
                for(int i=30;i>=0;i--) {
                     if((1<<i) & arr[idx[j]]) s.push_back('1');
                     else s.push_back('0');
                 }
                 rev(s);
                 while(s.length() and s[s.length()-1]=='0') s.pop_back();
                 rev(s);
                 temp += s;
             } 
              
             int ans=0;
            for(int i=temp.size()-1;i>=0;i--) {
                if(temp[i]=='1') ans+=(1LL<<(temp.size()-i-1));
             }
             return ans;
         };
        int maxi = INT_MIN;
        vector<int> idx(n,0);
        rep(i,0,n) idx[i]=i;

        do {
             maxi = max(maxi,fun(idx));
            
        } while(next_permutation(all(idx)));
        
        return maxi;
    }
};