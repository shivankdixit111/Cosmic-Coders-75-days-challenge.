
class Solution {
public:
    vector<string> stringSequence(string target) {
          vector<string> ans;
          int n = target.length();
          string temp = ""; 
          for(int i=0;i<n;i++) {
            temp.push_back('a');
             
            while(temp[i]!=target[i]) {
                   ans.push_back(temp); 
                 temp[i] = char('a'+(temp[i]-'a'+1)%26);
            } 
            ans.push_back(temp); 
          }      
          return ans;
    }
};