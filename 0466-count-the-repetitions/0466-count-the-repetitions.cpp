class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
         int i=0,j=0,s2Count=0;
         while(i<n1) {
               for(auto it:s1) {
                   if(it==s2[j]) j++;
                   if(j==s2.length()) {
                      s2Count++;
                      j=0; //reset it to find a cycle
                   }
               }
               i++;
         }
        
        // Calculate the final result by dividing s2Count by n2
        return s2Count / n2;
    }
};