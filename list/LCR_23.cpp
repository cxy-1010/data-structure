# include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa=headA;
        ListNode* pb=headB;
        ListNode* ans;
        while(pb!=nullptr)
        {
            pa=headA;
            while(pa!=nullptr)
            {
                if(pa==pb) return pb;
                pa=pa->next;
            }
            pb=pb->next;
        }
        return NULL;
    }
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr||headB==nullptr) return nullptr;
        ListNode* pa=headA;
        ListNode* pb=headB;
        while(pa!=pb)
        {
            pa=(pa==nullptr)?headB:pa->next;
            pb=(pb==nullptr)?headA:pb->next;
        }
        return pa;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr)
        {
            slow=slow->next;
            if(fast->next==nullptr) return nullptr;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(fast==nullptr) return nullptr;
        fast=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};