class Solution {
    private:
    int calcl(int a,int b,int c, int d,vector<vector<int>> &grid) {
       int sum=0;
       int i=a;
          for(int j=b;j>=d;j--) {
             sum+=grid[i][j];i++;
             if(i>c) break;
          }
          
       return sum;
    }
    int calcr(int a,int b,int c,int d,vector<vector<int>> &grid) {
      int sum=0;
       int i=a;
          for(int j=b;j<=d;j++) {
             sum+=grid[i][j];
             i++;
             if(i>c) break;
          }


       return sum;
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
         priority_queue<int> pq;
         vector<vector<int>> leftsum=grid,rightsum=grid;
          
         int n=grid.size();
         int m=grid[0].size();
              
        
        //  for(int i=1;i<m;i++) {

        //  }
                 map<int,int> mp;
        for(int sz=2;sz<=min(n,m)/2+1;sz++) {
            for(int i=sz-1;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if((i-sz+1>=0) and (sz-1+i)<n and (j-sz+1>=0) and (sz-1+j)<m) { 
                         int up=i-(sz-1), down=i+(sz-1), left=j-(sz-1), right=j+(sz-1);
                         int sum=0;
                         if(sz!=2)
                           sum=calcl(up,j,i,left,grid)+calcl(i,right,down,j,grid)+calcr(i+1,left+1,down-1,j-1,grid)+calcr(up+1,j+1,i-1,right,grid);
                         else 
                           sum=calcl(up,j,i,left,grid)+calcl(i,right,down,j,grid)+calcr(i,left,down,j,grid)+calcr(up,j,i,right,grid),sum/=2;
                         
                        //  cout<<i<<" "<<j<<" "<<sz<<"--> "<<up<<" "<<down<<" "<<left<<" "<<right<<" "<<sum<<endl;
                         if(mp[sum]==0) {
                           pq.push(sum);
                           mp[sum]++;
                         }
                    }
                } 
            }
        }
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mp[grid[i][j]]==0) { 
                    mp[grid[i][j]]++;
                    pq.push(grid[i][j]);
                }
            }
        }

         vector<int> ans;  int cnt=3;
        while(cnt--) {
            if(pq.empty()) break;
              ans.push_back(pq.top());
             pq.pop();
        }
        return ans;
    }
};