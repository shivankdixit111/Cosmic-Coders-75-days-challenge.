class Solution {
public:
    string stringHash(string s, int k) {
        int  n = s.length();
        int len = n/k;
        string res=""; 

        for(int i=0;i<=n-k;i+=k) {
            string temp="";
            for(int j=i;j<(i+k);j++) temp.push_back(s[j]);
            int sum=0;   
            for(int j=0;j<temp.length();j++) sum+=(temp[j]-'a');
            res.push_back(char(sum%26+'a'));
        }
       
        return res;
    }
};