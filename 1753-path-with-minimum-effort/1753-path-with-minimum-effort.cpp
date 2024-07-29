class Solution {
public:
    bool isvalid(int x, int y, int n, int m) {
        if(x<0 or y<0 or x>=n or y>=m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;        
        set<pair<int,pair<int,int>>> st;

        pq.push({0,{0,0}});
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        vector<vector<int>> dist(n,vector<int>(m+1,1e9));
        int ans=INT_MAX;

        while(pq.size()) {
            int diff=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
        
            if(x==n-1 and y==m-1) {
                return diff;
            }
            for(int i=0;i<4;i++) {
                    int x1 = x+dx[i];
                    int y1 = y+dy[i];
                    if(isvalid(x1,y1,n,m)) {

                        int dff=abs(heights[x1][y1]-heights[x][y]);

                        if(max(dff,diff)<dist[x1][y1]) {
                            dist[x1][y1] = max(dff,diff);
                            pq.push({max(dff,diff),{x1,y1}}); 
                        }

                    }
             }
        }
        return ans;
    }
};