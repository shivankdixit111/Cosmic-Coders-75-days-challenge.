class Solution {
public:
    int findmax(int i, int j, int i1, int m, vector<vector<char>> &matrix, vector<vector<int>> &psum) {
        int low=j,high=m,a=-1;
        
        while(low<=high) {
            int mid = low+ (high-low)/2;

            long ans = psum[i-1][j-1] + psum[i1][mid] - psum[i1][j-1] - psum[i-1][mid];
            if(ans==(i1-i+1)*(mid-j+1)) {
                low=mid+1;
                a=ans;
            } else {
                high=mid-1;
            }
        }
        if(a==-1) {
            a=(i1-i+1)*(high-j+1);
        }
        return a;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        vector<vector<int>> psum(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + (matrix[i-1][j-1]=='1');
            }
        }

        int maxi=0;
        
        for(int i=1;i<=n;i++) {
           for(int j=1;j<=m;j++) {
              for(int i1=i;i1<=n;i1++) {
                 if(matrix[i1-1][j-1]!='1') break;
                 maxi = max(maxi, findmax(i,j,i1,m,matrix,psum));
              }
           }
        }

        return maxi;
    }
};