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
    ListNode *detectCycle(ListNode *head) {
         ListNode* hare = head, *tortoise = head;

        while(hare and hare->next and hare->next->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
            
             if(hare==tortoise)  {
                 // reset slow to head again their again collision point will be starting node
                 // for proof  watch striver lecture
                 tortoise = head;
                 while( tortoise != hare ) {
                    tortoise = tortoise->next;
                    hare = hare->next;
                 }
                 return tortoise;
             }
        }
        return NULL;
    }
};