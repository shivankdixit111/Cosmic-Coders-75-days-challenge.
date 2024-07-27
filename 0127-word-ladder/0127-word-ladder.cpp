class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(),m = wordList[0].size();
        
        queue<pair<string,int>> q;
        set<string> vis;
        q.push({beginWord,1});
        set<string> st(wordList.begin(),wordList.end());

        int ans=0;

        while(q.size()) {
            string temp = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(temp==endWord) {
                ans=dist;
            }

            for(int i=0;i<temp.length();i++) {
                char prev=temp[i];
                for(char ch='a';ch<='z';ch++) {
                   temp[i]=ch;
                   if(st.count(temp) and !vis.count(temp)) {
                      q.push({temp,dist+1});
                      vis.insert(temp);
                   }
                }
                temp[i]=prev;
            }
        }

        return ans;
    }
};