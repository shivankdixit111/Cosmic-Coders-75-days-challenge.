class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
         
        int a1 = (c1[0]-'a');
        int a2 = c1[1];
                int b1 = (c2[0]-'a');
        int b2 = c2[1];

        if(a1%2==b1%2) {
            if(a2%2==b2%2) return true;
            return false;
        } else {
             if(a2%2!=b2%2) return true;
            return false;
        }
    }
};