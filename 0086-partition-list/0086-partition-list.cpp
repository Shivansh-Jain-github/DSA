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
 typedef ListNode* ll;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ll ltail = left, rtail = right;

        while(head){
            if(head->val < x){
                ltail->next = head;
                ltail = ltail->next;
            } else {
                rtail->next = head;
                rtail = rtail->next;
            }
            head = head->next;
        }
        ltail->next = right->next;
        rtail->next = nullptr;
        return left->next;       
    }
};