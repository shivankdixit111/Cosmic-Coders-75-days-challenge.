class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++) {
            string temp=s;
            //left rotate
            rotate(temp.begin(),temp.begin()+i+1,temp.end());
            if(temp==goal) { 
                return true;
            }
        }
        return false;
    }
};