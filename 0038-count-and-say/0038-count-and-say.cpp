class Solution {
public:
    string countAndSay(int n) {
        string temp="1";
        
        for(int i=2;i<=n;i++) {
            string ans="";
            int n1=temp.length();
           for(int j=0;j<temp.length();j++) {
               int cnt=1;
               while(j<n1-1 and temp[j]==temp[j+1]) cnt++,j++;
               ans.push_back(char(cnt+'0'));
               ans.push_back(temp[j]);
           }
           temp=ans;
        }
        return temp;
    }
};