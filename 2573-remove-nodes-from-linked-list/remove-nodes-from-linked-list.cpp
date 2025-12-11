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
    ListNode* removeNodes(ListNode* head) {
        ListNode* back = nullptr;
        ListNode* curr = head;
        while(curr->next)
        {
            ListNode* front = curr->next;
            curr->next = back;
            back = curr;
            curr = front;
        }
        curr->next = back;
        int maxi = curr->val;
        ListNode* current = curr->next;
        ListNode* backk = curr;
        while(current)
        {
            if(current->val < maxi)
            {
                backk->next = current->next;
                maxi = max(maxi, current->val);
                current = current->next;
            }
            else
            {
                maxi = max(maxi, current->val);
                backk = current;
                current = current->next;
            }
        }
        back = nullptr;
        while(curr->next)
        {
            ListNode* next = curr->next;
            curr->next = back;
            back = curr;
            curr = next;
        }
        curr->next = back;
        return curr;
    }
};