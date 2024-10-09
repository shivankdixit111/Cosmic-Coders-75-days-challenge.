class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
          vector<int> mustContainCord = coordinates[k];

        sort(coordinates.begin(),coordinates.end(),[&](vector<int> &a, vector<int> &b) {
            if( a[0]==b[0] ) return a[1]>b[1];
            return a[0]<b[0];
        });

        // lis that must contain kth element 

        vector<int> lis;
        bool flag = false;
        for(int i=0; i<coordinates.size(); i++) {
             if(coordinates[i]==mustContainCord) flag = true;
            if( coordinates[i][0] == mustContainCord[0] and  coordinates[i][1] != mustContainCord[1]) {
                continue;
            }

             if(coordinates[i][1]>= mustContainCord[1] and !flag)  continue;

            auto it = lower_bound( lis.begin(),lis.end(), coordinates[i][1] ); 
            if(lis.empty() or it==lis.end()) {
                lis.push_back(coordinates[i][1]);
            } else {
                if(*it != mustContainCord[1]  )
                *it = coordinates[i][1];
            } 
        } 
        
        return lis.size();

    }
};