#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
private:
    unordered_map<Node *, Node *> nodeMap;
public:
    // hashMap递归法
    Node* copyRandomList1(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (nodeMap[head] == nullptr) {
            Node *newNode = new Node(head->val);
            nodeMap[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return nodeMap[head];
    }

    // 复制+断链法
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        // 复制原有链表
        Node *cur = head;
        while (cur != nullptr) {
            Node *temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        // 复制random结点
        cur = head;
        while (cur != nullptr) {
            Node *temp = cur->next;
            if (cur->random) {
                temp->random = cur->random->next;
            }
            cur = temp->next;
        }
        // 断链
        Node *pre = head;
        cur = head->next;
        Node *newHead = cur;
        while (cur->next) {
            Node *temp = cur->next->next;
            pre->next = cur->next;
            cur->next = temp;
            pre = pre->next;
            cur = temp;
        }
        cur->next = nullptr;
        pre->next = nullptr;
        return newHead;
    }

    void printNodes(Node *head) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr) {
                cout << "val is:" << temp->val << ", random is:" << temp->random->val << endl;
            } else {
                cout << "val is:" << temp->val << ", random is null" << endl;
            }
            temp = temp->next;
        }
    }

    Node *testNode() {
        Node *node1 = new Node(7);
        Node *node2 = new Node(13);
        Node *node3 = new Node(11);
        Node *node4 = new Node(10);
        Node *node5 = new Node(1);
        node1->next = node2;
        node1->random = nullptr;
        node2->next = node3;
        node2->random = node1;
        node3->next = node4;
        node3->random = node5;
        node4->next = node5;
        node4->random = node3;
        node5->next = nullptr;
        node5->random = node1;
        return node1;
    }
};

int main() {
    Solution s;
    Node *testHead = s.testNode();
    Node *res = s.copyRandomList(testHead);
//    s.printNodes(res);
}
