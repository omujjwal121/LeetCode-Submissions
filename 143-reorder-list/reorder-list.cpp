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
        deque<ListNode*> d;
        ListNode* temp = head;
        while(temp)
        {
            d.push_back(temp);
            temp = temp->next;
        }
        if(d.size()==1) return;
        while(d.size()>1)
        {
            ListNode* front = d.front();
            ListNode* back = d.back();
            front->next = back;
            d.pop_front();
            back->next = d.front();
            d.pop_back();
            if(d.size() == 1) d.front()->next = nullptr;
            else if(d.size() == 0) back->next = nullptr;
        }
    }
};