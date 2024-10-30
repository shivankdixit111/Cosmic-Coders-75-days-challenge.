class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int i=0,ans=0;
        while(i<n) {
            int j=i-1;
            while(j>=0 and arr[j]>arr[i]) j--;
            int cnt = i-j;
            int len = 0;
            j = i;
            while(j<n and min(arr[i],arr[j])==arr[i]) len++,j++; 
            int x = (((arr[i]%mod *1LL* len%mod)%mod) *1LL* (cnt%mod))%mod;
            ans = (ans + x)%mod;
            i++;
        }
        return ans;
    }
};