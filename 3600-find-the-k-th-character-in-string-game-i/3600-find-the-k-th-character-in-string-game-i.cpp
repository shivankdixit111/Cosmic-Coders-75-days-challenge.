class Solution {
public:
    char kthCharacter(int k) {
        string s ="a";
        while(s.length()<k) {
            string temp = s;
            for(auto &it:temp) {
                it = char((it-'a'+1)%26 + 'a');
            }
            // cout<<temp<<endl;
            s += temp;
        }
        // cout<<s<<endl;
        return s[k-1];
    }
};