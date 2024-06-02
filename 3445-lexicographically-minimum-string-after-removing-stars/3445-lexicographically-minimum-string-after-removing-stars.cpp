class Solution {
public:
    string clearStars(string s) {
        
        int n=s.length();
        vector<int> vis(100005,0);
        vector<int> arr[100005];
        vector<int> star;
        
        for(int i=0;i<n;i++) {
            if(s[i]>='a' and s[i]<='z')
            arr[s[i]-'a'].push_back(i);
            else {
            
               for(int i=0;i<26;i++) {
                    if(arr[i].size()) {
                        vis[arr[i].back()]=1;
                        arr[i].pop_back();
                        break; 
                    }
                }
            vis[i]=1;
            }
        }
        
       
        
        string temp="";
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                temp+=s[i];
            }
        }
        
        return temp;
        
        
        
        
        return "shivank";
    }
};