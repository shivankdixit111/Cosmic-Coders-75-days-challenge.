class Solution {
public:
    int findmaximum(int i, int j, vector<int> &arr) {
        int maxi=INT_MIN ;
        for(int k=i;k<=j;k++) {
            maxi=max(maxi,arr[k]);
        }
        return maxi;
    }

    int rec(int i, int n, vector<int> &arr, int k, vector<int> &dp){
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        
        int ans=INT_MIN;
        for(int j=i;j<min(i+k,n);j++) {
                    int findmaxi=findmaximum(i,j,arr)*(j-i+1);
                    //   cout<<j<<" "<<ans<<" --- ";
                    ans=max(ans,findmaxi+rec(j+1,n,arr,k,dp));     
        }
        // if(i==2)
        // cout<<ans<<" ";
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int cnt=0;
        vector<int> dp(n,-1);
        return rec(0,n,arr,k,dp);
    }
};