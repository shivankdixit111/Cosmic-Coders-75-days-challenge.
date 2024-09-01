  struct TrieNode {
     TrieNode* arr[2]; 
     TrieNode() {
        arr[0]=NULL;
        arr[1]=NULL;
     }
  };
 

  void insert(TrieNode* root, int val) {
       TrieNode* temp = root; 
       
       for(int i=31;i>=0;i--) {
           // checking ith bit is set or not
           int bit = ((1<<i) & val) ? 1: 0;

           if(temp->arr[bit]==NULL) {
              temp-> arr[bit] = new TrieNode();
           }
        //    cout<<i<<" - "<<bit<<" ";
           temp = temp-> arr[bit];
       }
    //    cout<<endl;
  }
 
  int get_max_xor_of_two(TrieNode* root, int val) {
       TrieNode* temp = root;
        int num=0;
       
       for(int i=31;i>=0;i--) {
           // checking ith bit is set or not
           int bit = ((1<<i) & val) ? 1: 0;
           
           // for maximum xor find the opposite bit
           if(temp->arr[1-bit]!=NULL) {

              num += (1-bit) ? (1<<i) : 0;
              temp = temp-> arr[1-bit];

           } else if(temp->arr[bit]!=NULL) {
              // if opposite bit not present go to same bit
              num += bit ? (1<<i) : 0; 
              temp = temp-> arr[bit];
           }
       }
       return num ^ val;
  }
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) { 
        TrieNode* root = new TrieNode();
        for(auto it:nums) {
            insert(root,it);
        }
        int maxi = INT_MIN;

        for(auto it:nums) { 
            maxi = max(maxi, get_max_xor_of_two(root,it));
        }
        return maxi;
    }
};