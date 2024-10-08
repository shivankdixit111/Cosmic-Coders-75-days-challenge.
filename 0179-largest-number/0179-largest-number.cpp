class Solution {
public:
      static bool cmp(int a,int b){
            string s = to_string(a);
            string t = to_string(b);
            
            if( (s+t) > (t+s)) return true;
            return false; 
        }
    void removeFrontzero(string &s) {
        reverse(s.begin(),s.end());
        while(s.length() and s[s.length()-1]=='0') s.pop_back();
        reverse(s.begin(),s.end());
        if(!s.length()) s="0";
    }

    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);

        string s = "";

        for(auto it:arr)  s+=to_string(it);

        removeFrontzero(s);

        return s;
    }
};