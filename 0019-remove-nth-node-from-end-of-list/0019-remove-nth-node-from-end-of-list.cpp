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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        int cnt=0;
        while(fast) {
             //move fast till it covers n nodes  ie  2*n
             // slow = n 
             fast = fast->next; 
             cnt++;
             
             if(cnt==n) {
                break;
             }
        }

        if( fast == NULL ) return head->next;
       
        // now move both one step
        // remaining for fast = l - 2*n
        // slow = n + l - 2*n  -> l-n  slow will be exacly at l-n position     proved

        while(fast!=NULL) {
            fast = fast->next;
            // access previous slow to delete slow 
            if(fast==NULL) break;
            slow = slow->next;
        }


        ListNode* delNode = slow->next;

        slow->next = slow->next->next; 
        
        delete delNode; // to avoid wastage of memory as c++ has no garbage collection
        
        return head;
        
    }
};