class Solution {
public:
    bool isvalid(int x,int y,int n,int m) {
        if(x<0 or y<0 or x>=n or y>=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>> distance(n+1,vector<int>(m+1,1e9));
        distance[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({grid[0][0],{0,0}});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};

        while(pq.size()) {
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();

            if(x==n-1 and y==m-1)  {
                // cout<<dist<<" ";
                continue;
            }

            for(int i=0;i<4;i++) {
                    int x1=x+dx[i];
                    int y1=y+dy[i];
                    if(isvalid(x1,y1,n,m)) {
                        if( max(dist,grid[x1][y1]) < distance[x1][y1]) {
                            distance[x1][y1] = max(dist,grid[x1][y1]);
                            pq.push({distance[x1][y1],{x1,y1}});
                        }
                    }
             }
        } 

        return distance[n-1][m-1];
    }
};