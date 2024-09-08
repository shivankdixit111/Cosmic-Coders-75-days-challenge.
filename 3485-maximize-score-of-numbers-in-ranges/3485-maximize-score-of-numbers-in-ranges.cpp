class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end()); 
        long low=0,high= 1e15;
        int ans= low;
        auto check=[&](long mid) {
           long long n= start.size();
           long long st=start[0];
           for(int i=0;i<n;i++) {
                if(st> start[i]+d) return false;
                if(st<start[i]) {
                    st = start[i];
                }
                st+=mid;
           }
           return true;
        };

        while(low<=high) {
            long mid = (low+high)>>1;

            if(check(mid)) {
                ans= mid;
                low=mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};