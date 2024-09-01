class Solution {
public:
    int dpt[2001][2001];
    int dp[2001][2001];

    int funt(int i, int j, vector<int> &arr) {
        if(i==j) return dpt[i][j] = arr[i];
        if(i>j) return 0;
        if(dpt[i][j]!=-1) return dpt[i][j];
        // observation on dry run
        return dpt[i][j] = (funt(i,j-1,arr) ^ funt(i+1,j,arr));  
    }
    
    int fun(int i,int j, vector<int> &arr) {
        if(i>j) return 0;
        if(i==j) return dp[i][j]=arr[i];
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = max( max(fun(i,j-1,arr), funt(i,j,arr)), max(fun(i+1,j,arr),funt(i,j,arr)) );
    }
      
    vector<int> maximumSubarrayXor(vector<int>& arr, vector<vector<int>>& queries) {
            int n = arr.size();
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    dp[i][j]=-1;
                    dpt[i][j]=-1;
                }
            }
            vector<int> ans;

            for(auto it:queries) {
                ans.push_back(fun(it[0],it[1],arr));
            }
            
            return ans;
    }
};