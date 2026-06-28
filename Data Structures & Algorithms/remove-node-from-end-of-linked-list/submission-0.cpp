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
        int lenoflist=0;
        ListNode *travel=head;
        while(travel!=nullptr){
            travel=travel->next;
            lenoflist+=1;
        }
        if (n == lenoflist) {
            ListNode* new_head = head->next; 
            delete head;                  
            return new_head;              
        }
        int i=0;
        ListNode *travel2=head;
        while(i<lenoflist-n-1){
            travel2=travel2->next;
            i+=1;
        }
        ListNode *prev=travel2;
        ListNode *deleted_node=travel2->next;
        ListNode *back=deleted_node->next;
        prev->next=back;
        delete deleted_node;
        return head;
    }
};
