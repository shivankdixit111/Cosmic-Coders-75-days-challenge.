class Solution {
public:
    const int mod = 1e9+7;
    int rec(int currIdx, int inv, vector<int> &req, vector<vector<int>> &dp ) {

        if(currIdx==0) {
            if(inv==0) return 1;
            else return 0;
        }

        if(dp[currIdx][inv]!=-1) return dp[currIdx][inv];

        if(req[currIdx]!=-1) {
            if(req[currIdx]!=inv) return 0;
        }

        int ans=0;
        for(int i=0;i<=min(currIdx,inv);i++) {
            ans += rec(currIdx-1, inv-i,  req,dp);
            ans %= mod;
        } 
        return  dp[currIdx][inv] = ans;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n,-1);
        sort(requirements.begin(),requirements.end(),[&](vector<int> &a,vector<int>&b){
            return a[0] <= b[0];
        });
        for(auto it:requirements) {
            // cout<< it[0] <<" "<<it[1]<<endl;
            req[it[0]] = it[1];
        }
        if(req[0]!=-1 and req[0]!=0)  return 0;
        vector<vector<int>> dp(n+1,vector<int>(401,-1));
        return rec(n-1,req[n-1],req,dp);
    }
};