
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
#define N 1e5+1

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<long long> cntDiv(1e5+1),gcdCnt(1e5+1,0);
        for(auto it:nums) {
            for(int i=1;i*i<=it;i++) {
                if(it%i==0) {
                    cntDiv[i]++;
                    if(i != (it/i)) {
                        cntDiv[it/i]++;
                    }
                } 
            }
        }

        for(int i=N-1;i>=1;i--) {
            int cnt = cntDiv[i];
            gcdCnt[i] = (cnt*1LL*(cnt-1))/2 ;
            for(int j= i*2;j<=N-1;j+=i) {
                gcdCnt[i] -= gcdCnt[j];
            }
        }

        vector<long long> psum(N+1);
        vi temp;
        for(int i=1;i<=N-1;i++) {
            psum[i] = psum[i-1] + gcdCnt[i];
        }
        
       for(auto it:queries) {
            // int low=0,high=N*(N-1)/2,ans=-1;
            // while(low<=high) {
            //     int mid = (low+high)>>1;

            //     if(psum[mid]>it) {
            //         ans = mid;
            //         high = mid-1;
            //     } else low = mid+1;
            // }
            // temp.push_back(ans);
            auto i1 = upper_bound(all(psum),it)-psum.begin();
            temp.pb(i1);  
       }

       return temp;

    }
};