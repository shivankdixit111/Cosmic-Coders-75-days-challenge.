class Solution {
public:
    bool rec(int i, int n, vector<int> &nums, vector<int> &dp) { 
        if(i>=n-1) return true;   
        if(dp[i]!=-1) return dp[i];    
        
        bool ans=false; 
        for(int j=1;j<=nums[i];j++) { 
            if(rec(i+j,n,nums,dp)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
         int n = nums.size();
          vector<int> dp(n+1,0);
        //  return  rec(0,n,nums,dp);

        //------------ tabulation
        // dp[0] = true;
        // for(int i=0;i<n;i++) { 
        //     if(dp[i]==false) continue;
        //     for(int j=1;j<=nums[i];j++) { 
        //         if( (i+j)<n and !dp[i+j] ) {
        //              dp[i+j] = true;  
        //         }
        //     } 
        // }
        // return dp[n-1];


        //-----------------greedy
        int maxi = 0;
        for(int i=0;i<n;i++) {
              if(i>maxi) return false;
           maxi = max(maxi,i+nums[i]);
        }
        return  true;
    }
};