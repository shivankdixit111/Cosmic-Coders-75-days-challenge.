/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
         //optimized version tortoise and hare algorithm
         ListNode* hare = head, *tortoise = head;
         
         while(hare->next and hare->next->next!=NULL) {
               hare = hare->next->next;
            
             tortoise = tortoise->next;
         }
         // in even number of nodes hare will not reach at the last node of ll
         if(hare->next) tortoise = tortoise->next;
         return tortoise;
    }
};