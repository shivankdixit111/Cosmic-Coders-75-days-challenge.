/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ---------- Brute force  tc-O(n*logn)  sc-O(n)
        //  unordered_map<ListNode*,int> mp;
        //  ListNode* temp = head;
        //  while(temp!=NULL) {
        //     if(mp[temp]) {
        //         return true;
        //     }
        //     mp[temp]++;
        //     temp = temp->next;
        //  }
        //  return false;

        // ----------- Optimized Version   tc- O(n) sc-O(1)

        ListNode* hare = head, *tortoise = head;

        while(hare and hare->next and hare->next->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            
             if(hare==tortoise) return true;
        }
        return false;
    }
};