class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(auto it:words) mp[it]++;
        int cnt=0;
        for(auto it:mp) {
            int i=0,j=0;
            while(i<s.length() and j<it.first.length()) {
                if(it.first[j]==s[i]) i++,j++;
                else i++;
            }
            cnt+= (j==it.first.length()) ? it.second : 0;
        }
        return cnt;
    }
};