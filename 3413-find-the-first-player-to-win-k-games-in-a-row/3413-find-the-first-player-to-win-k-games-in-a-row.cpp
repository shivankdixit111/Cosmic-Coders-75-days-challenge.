class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int winner=max(skills[0],skills[1]),n=skills.size();
        map<int,int> mp;
        mp[winner]++;

        for(int i=1;i<n-1;i++) {
             if(winner<skills[i+1]) {
                winner=skills[i+1];
             } 
               mp[winner]++;
        }

        for(int i=0;i<n;i++) {
            if(mp[skills[i]]>=k) return i;
        }
         for(int i=0;i<n;i++) {
            if(skills[i]==winner) return i;
        }
        return n;
    }
};