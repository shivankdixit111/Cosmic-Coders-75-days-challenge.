class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        vector<vector<int>> psum(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] +(matrix[i-1][j-1]==1);
            }
        }
        int cnt=0;
      
 
        for(int sz=1;sz<=min(n,m);sz++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=m;j++) {
                   int x2=i+sz-1,y2=j+sz-1;
                   if(x2>n or y2>m) break;
                   int sum = psum[x2][y2] - psum[x2][j-1] - psum[i-1][y2] + psum[i-1][j-1];
                   if(sum==(y2-j+1)*(x2-i+1)) {
                      cnt++;
                   }
                } 
            }
        }
            return cnt;
        }
    };
