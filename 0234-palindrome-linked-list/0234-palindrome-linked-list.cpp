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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head, *fast = head;

        while(fast and fast->next and fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast->next) {
            // even length
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* prevv= slow, *curr = slow->next, *nextt;
        prevv->next = NULL;
        while(curr!=NULL) {
             nextt = curr->next;

             curr->next = NULL;
             curr->next = prevv;
             prevv = curr;

             curr = nextt;
        }

        ListNode* temp = head;
        curr= prevv;

        while(temp and temp->next!=NULL) {
            if( temp->val != curr->val )  return false;
            temp = temp->next;
            curr = curr->next;
        }
        
        return true;

    }
};