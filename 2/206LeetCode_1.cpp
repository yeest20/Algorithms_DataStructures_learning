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
        ListNode new_list_head;
        new_list_head.next = NULL;

        for(ListNode* p = head, *q; p; ){
            q = p->next;
            p->next = new_list_head.next;
            new_list_head.next = p;
            p = q;
        } 
        return new_list_head.next;
    }
};
