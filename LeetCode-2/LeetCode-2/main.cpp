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
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
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
