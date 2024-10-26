class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.size();  // Length of s1
        int len2 = s2.size();  // Length of s2
        
        // A map to store the index of s2 and corresponding (s1_count, s2_count)
        unordered_map<int, pair<int, int>> memo;
        
        int s1Count = 0;  // Number of times s1 has been concatenated
        int s2Count = 0;  // Number of times s2 has been fully matched
        int index = 0;    // Current index in s2
        
        while (s1Count < n1) {  // Loop until we use s1 n1 times
            for (char c : s1) {  // Traverse through each character in s1
                if (c == s2[index]) {  // If characters match
                    index++;
                    if (index == len2) {  // If we have matched the entire s2
                        s2Count++;
                        index = 0;  // Reset index for the next round
                    }
                }
            }
            s1Count++;  // Increment the count of s1 used
            
            // Check if we have seen this index of s2 before
            // if (memo.find(index) != memo.end()) {
            //     auto& prev = memo[index];
            //     int prev_s1Count = prev.first;
            //     int prev_s2Count = prev.second;

            //     // Calculate the cycle length and the number of cycles
            //     int cycleLen = s1Count - prev_s1Count;
            //     int cycleCount = (n1 - prev_s1Count) / cycleLen;

            //     // cout<<" -- "<<index<<" "<<s1Count<<" "<<s2Count<<endl;

            //     // Fast forward through the cycles
            //     s1Count = prev_s1Count + cycleCount * cycleLen;
            //     s2Count = prev_s2Count + cycleCount * (s2Count - prev_s2Count); 

            //     cout<<index<<" "<<prev_s1Count<<" "<<prev_s2Count<<" "<<cycleLen<<" "<<cycleCount<<" "<<s1Count<<" "<<s2Count<<endl;
            // }
            // // cout<<index<<" "<<s1Count<<" "<<s2Count<<endl;
            
            // // Store the current state in the map
            // memo[index] = {s1Count, s2Count};
        }
        
        // Calculate the final result by dividing s2Count by n2
        return s2Count / n2;
    }
};