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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = head,*prevv=head,*nextt;
        temp = temp->next;
        prevv->next = NULL;

        while(temp!=NULL) {
            nextt= temp->next; 
            temp->next = NULL;
            
            temp->next = prevv;
            prevv = temp; 

            temp = nextt; //go to next
        } 
        

        return prevv;
        
    }
};