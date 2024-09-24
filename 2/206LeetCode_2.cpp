/*************************************************************************
	> File Name: 206LeetCode.cpp
	> Author:YEE 
	> Mail:15509992895@163.com 
	> Created Time: Sat 21 Sep 2024 02:59:10 PM CST
 ************************************************************************/
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
        if(head == NULL || head->next == NULL) return head;
        ListNode* tail = head->next;
        ListNode* new_head = reverseList(head->next);
        tail->next = head;
        return new_head;
    }
};
