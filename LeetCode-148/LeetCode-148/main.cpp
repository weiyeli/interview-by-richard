//
//  main.cpp
//  LeetCode-148
//
//  Created by liweiye on 2020/6/28.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;
        dummyHead->next = head;
        int length = 0;
        ListNode* cur = head;
        while (cur) {
            length += 1;
            cur = cur->next;
        }

        for (int i = 1; i < length; i <<= 1) {
            cur = dummyHead->next;
            tail = dummyHead;
            while (cur) {
                ListNode* left = cur;
                ListNode* right = cut(cur, i);
                cur = cut(right, i);
                tail->next = merge(left, right);

                // 维持 tail 始终是已排序的链表的最后一个结点
                while (tail->next) {
                    tail = tail->next;
                }
                // 串联起还没有排序的结点
                tail->next = cur;
            }
        }

        return dummyHead->next;
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        cur->next = l1 ? l1 : l2;
        return dummyHead->next;
    }

    ListNode* cut(ListNode* l, int n) {
        // 向前走 n-1 步
        while (--n && l) {
            l = l->next;
        }
        // 说明链表不足 n 个节点
        if (!l) return nullptr;
        ListNode* head = l->next;
        l->next = nullptr;
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    l4->next = l1;
    l1->next = l2;
    l2->next = l3;
    Solution s = Solution();
    ListNode* head = s.sortList(l4);
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}
