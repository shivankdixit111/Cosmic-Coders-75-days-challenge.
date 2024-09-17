 
 vector<int> prefix_function(string s)
{   
    // Longest suffix that matches with prefix
    // lps array is used in kmp

    int n = s.length();

    vector<int> prefix(n, 0);
    int i = 0, j = 1;

    while (j < n)
    {
        if (s[i] == s[j])
        {
            i++;
            prefix[j] = i;
            j++;
        }
        else
        {
            if (i != 0)
            {
                i = prefix[i - 1];
            }
            else
            {
                j++;
            }
        }
    }
    return prefix;
}

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n=  words.size(),m=  target.size();
       
        vector<vector<int>> p;
        for(auto it:words) {
            p.push_back( prefix_function( it + '#' + target ) );
        }

        int cnt=0;

        while(m>0)  {
            int maxi =0;
            for(int i=0;i<n;i++) {
                maxi = max(maxi, p[i][m + words[i].size()]);
            }
            cnt++;
            if(maxi==0) return -1;
            m-=maxi;
        }

        return cnt;
 
    }
};