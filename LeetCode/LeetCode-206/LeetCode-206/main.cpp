//
//  main.cpp
//  LeetCode-206
//
//  Created by liweiye on 2020/6/28.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        cur = head;
        while (cur)
        {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s = Solution();
    ListNode *head = s.reverseList(node1);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
}
