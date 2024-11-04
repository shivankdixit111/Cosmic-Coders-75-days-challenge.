class Solution {
public:
    vector<vector<int>> dp;
    int rec(int idx, int mask,int n) {
        if(idx==n) {
            return 0;
        }
        if(dp[idx][mask]!=-1) return dp[idx][mask];

        int ans=0;
        for(int i=0;i<=9;i++) { 
           if(mask==0 and i==0) continue;
           if(!((1<<i)&mask)) {
              ans += 1 + rec(idx+1,mask|(1<<i),n);
           }
        }
         return dp[idx][mask] =  ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        dp.resize(n+1,vector<int>((1<<(10)),-1));
        return  1 + rec(0,0,n); //1 is added for one zero
    }
};