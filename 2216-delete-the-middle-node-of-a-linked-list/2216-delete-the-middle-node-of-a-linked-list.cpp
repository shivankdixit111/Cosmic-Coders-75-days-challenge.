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
    ListNode* deleteMiddle(ListNode* head) {
        if( head->next==NULL) return NULL;
        ListNode* fast = head, *slow = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            if(fast!=NULL and fast->next!=NULL)
            slow = slow->next;
        }
        // slow = medium      access previous slow to delete slow
        // even length
        if(fast) {
            fast = fast->next; 
            // slow = slow->next;   avoid bcoz we are accessing previous slow
        }
        
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
    }
};