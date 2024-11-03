struct Node{
    string word;
    int index;
    Node(string &word, int index) :word(word),index(index) {}
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<Node> bucket[26];
        for(auto word:words) {
           bucket[(word[0]-'a')].push_back(Node(word,0));
        }
        int ans=0;
        for(auto it:s) {
            auto x = bucket[it-'a']; 
            bucket[it-'a'].clear();
            for(auto &node:x) { 
                node.index++;
                if(node.index==node.word.length()) ans++;
                else {
                    bucket[node.word[node.index]-'a'].push_back(node);
                }
            }
        }
        return ans;
    }
};