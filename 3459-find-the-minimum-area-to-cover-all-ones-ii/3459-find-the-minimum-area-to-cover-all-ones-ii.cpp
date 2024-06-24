class Solution {
    private:
    int calcarea(int a,int c,int b,int d,vector<vector<int>> &grid) {
        int up=31,down=-1,left=31,right=-1;
        for(int i=a;i<c;i++) {
            for(int j=b;j<d;j++) {
                if(grid[i][j]) {
                    up=min(i,up);
                    down=max(i,down);
                    left=min(j,left);
                    right=max(j,right);
                }
            }
        }
        if(up==31) return 0;

        return (down-up+1)*(right-left+1);
    } 
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mini=INT_MAX;
        //case1
        for(int i=0;i<m;i++) 
          for(int j=i+1;j<m;j++)
            mini=min(mini,calcarea(0,n,0,i,grid)+calcarea(0,n,i,j,grid)+calcarea(0,n,j,m,grid));
        //case2
        for(int i=0;i<n;i++) 
          for(int j=i+1;j<n;j++)
            mini=min(mini,calcarea(0,i,0,m,grid)+calcarea(i,j,0,m,grid)+calcarea(j,n,0,m,grid));
        //case 3
        for(int i=0;i<m;i++) {
            int one=calcarea(0,n,0,i,grid);
          for(int j=0;j<n;j++) {
             mini=min(mini,one+calcarea(0,j,i,m,grid)+calcarea(j,n,i,m,grid));
          }
        }
      
        //case 4
        for(int i=m-1;i>=0;i--) {
            int one=calcarea(0,n,i,m,grid);
           for(int j=0;j<n;j++) {
               mini=min(mini,one+calcarea(0,j,0,i,grid)+calcarea(j,n,0,i,grid));
           }
        }
        
        //case 5
        for(int i=0;i<n;i++) {
            int one=calcarea(0,i,0,m,grid);
           for(int j=0;j<m;j++) {
               mini=min(mini,one+calcarea(i,n,0,j,grid)+calcarea(i,n,j,m,grid));
           }
        }
       
        //case 6
        for(int i=n-1;i>=0;i--) {
            int one=calcarea(i,n,0,m,grid);
           for(int j=0;j<m;j++) {
               mini=min(mini,one+calcarea(0,i,0,j,grid)+calcarea(0,i,j,m,grid));
           }
        }
         

        return mini;

    }
};