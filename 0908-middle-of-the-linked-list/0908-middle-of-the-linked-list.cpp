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
        int cnt=0;
        ListNode* temp = head;
        while(temp!=NULL) {
            temp = temp->next;
            cnt++;
        }
        int i=0;
        temp = head;
        while(temp!=NULL) {
           if(i==cnt/2) {
              return temp;
           }
           temp = temp->next;
           i++;
        }
        return temp;
    }
};