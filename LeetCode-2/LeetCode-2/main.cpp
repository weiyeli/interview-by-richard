//
//  main.cpp
//  LeetCode-2
//
//  Created by Ricardo on 2021/10/11.
//

#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *tail = new ListNode(-1);
        int carry = 0;
        while (l1 || l2) {
            int res1 = l1 ? l1->val : 0;
            int res2 = l2 ? l2->val : 0;
            int sum = res1 + res2 + carry;
            int res = 0;
            if (sum >= 10) {
                carry = 1;
                res = sum % 10;
            } else {
                res = sum;
                carry = 0;
            }
            if (head->val == -1) {
                head->val = res;
                tail = head;
            } else {
                ListNode *temp = new ListNode(res);
                tail->next = temp;
                tail = temp;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry > 0) {
            tail->next = new ListNode(1);
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    ListNode *l11 = new ListNode(2);
    ListNode *l12 = new ListNode(4);
    ListNode *l13 = new ListNode(3);
    l11->next = l12;
    l12->next = l13;
    ListNode *l21 = new ListNode(5);
    ListNode *l22 = new ListNode(6);
    ListNode *l23 = new ListNode(4);
    l21->next = l22;
    l22->next = l23;
    ListNode *res = solution.addTwoNumbers(l11, l21);
    while (res) {
        printf("%d\n", res->val);
        res = res->next;
    }
}
