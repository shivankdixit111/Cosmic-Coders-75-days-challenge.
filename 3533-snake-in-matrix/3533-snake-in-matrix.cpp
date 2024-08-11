class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0,y=0,val=0;
        vector<vector<int>> arr(n,vector<int>(n));
        int cnt=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j]=cnt;
                cnt++;
            }
        }

        for(int i=0;i<commands.size();i++) { 
                if(commands[i]=="UP" and x>0) x-=1,val-=n;
                if(commands[i]=="RIGHT" and y<n-1) y+=1,val+=1;
                if(commands[i]=="DOWN" and x<n-1) x+=1,val+=n;
                if(commands[i]=="LEFT" and y>0) y-=1,val-=1;
        }
        return arr[x][y];
    }
};