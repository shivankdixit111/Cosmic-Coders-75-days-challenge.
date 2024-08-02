class Solution {
public: 
    vector<int> findlps(string s) {
        int n=s.length(),i=0,j=1;
        vector<int> lps(n,0);
        while(j<n) {
            if(s[i]==s[j]) {
                i++;
                lps[j]=i;
                j++;
            } else {
                if(i!=0) i=lps[i-1];
                else {
                    j++;
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        int n=s.length();

        vector<int> temp = findlps(s);
        int maxidx=INT_MIN;
        
        string ans= s.substr(0,temp[temp.size()-1]); 
        return ans;
    }
};