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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return ;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=nullptr &&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *second_half=slow->next;
        slow->next=nullptr;

        ListNode *prev=nullptr;
        ListNode *curr=second_half;
        while(curr!=nullptr){
            ListNode *next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
        }
        ListNode*first_half=head;
        second_half=prev;
        while(second_half!=nullptr){
            ListNode* tmp1 = first_half->next;
            ListNode* tmp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = tmp1;
            first_half = tmp1;
            second_half = tmp2;
        }
        
    }
};
