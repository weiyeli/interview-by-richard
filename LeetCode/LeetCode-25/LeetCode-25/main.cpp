//
//  main.cpp
//  LeetCode-25
//
//  Created by ricardooli on 2022/2/13.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) {
            return head;
        }
        ListNode* hair = new ListNode(0, head);
        ListNode* tail = hair;
        ListNode* pre = hair;
        while (pre->next) {
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    return hair->next;
                }
            }
            ListNode* next = tail->next;
            ListNode* newHead, *newTail;
            tie(newHead, newTail) = reverseLinkList(pre->next, tail);
            pre->next = newHead;
            newTail->next = next;
            pre = newTail;
            tail = pre;
        }
        return hair->next;
    }
    
    pair<ListNode*, ListNode*> reverseLinkList(ListNode* head, ListNode* tail) {
        // 反转链表其实就是pre和cur
        ListNode* pre = tail->next;
        ListNode* cur = head;
        while (pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            // 一定要先移动pre指针
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }
};

int main(int argc, const char * argv[]) {
    ListNode* node5 = new ListNode(5, nullptr);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    int k = 2;
    
    Solution s;
    
    ListNode* head = s.reverseKGroup(node1, k);
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << "->";
        } else {
            cout << endl;
        }
        head = head->next;
    }
    
    return 0;
}
