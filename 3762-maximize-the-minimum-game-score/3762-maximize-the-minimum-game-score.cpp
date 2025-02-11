#define ll long long int

class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        int n = points.size();
        auto check = [&](ll val) {
            ll transfer=0, total=0, skip=0;
            for(int i=0;i<n and total<=m;i++) {
                ll point = points[i];
                ll req = ceil((double)val/point);
                if(req <= transfer){
                    transfer = 0;
                    skip++;
                } else {
                    ll ops = ceil((double)(val - transfer*point)/point);
                    total += 2*ops-1;
                    total += skip;
                    transfer = max(ops-1, 0LL);
                    skip=0;
                }
            }
            return total<=m;
        };
        ll low=1,high=1e18,ans=0;
        while(low<=high) {
            ll mid = (low + high)>>1;
            if(check(mid)) {
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};