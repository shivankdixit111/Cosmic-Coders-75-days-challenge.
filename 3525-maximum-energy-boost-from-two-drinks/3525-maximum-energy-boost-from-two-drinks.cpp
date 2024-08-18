   
 #include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define revf(i,a,b) for(int i=b-1;i>=a;i--)
#define SUM(X) accumulate(X.begin(),X.end(),0LL)
class Solution { 
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        ll ans=0,ans1=0,n=a.size();
        
        vector<vector<ll>> dp(n+1,vi(2,0));
        dp[0][0]= a[0];
        dp[0][1]= b[0];

        rep(i,1,n) {
            dp[i][0] = max(dp[i][0], dp[i-1][0]+ a[i]);
            dp[i][1] = max(dp[i][1], dp[i-1][1]+ b[i]);

            if(i>=2) {
                dp[i][0] = max(dp[i][0], dp[i-2][1]+ a[i]);
                dp[i][1] = max(dp[i][1], dp[i-2][0]+ b[i]);
            }
       }
       return max(dp[n-1][0], dp[n-1][1]);
    }
};