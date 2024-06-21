#include <iostream>

using namespace std;

typedef struct _node {
    struct _node *left;
    struct _node *right;
    struct _node *parent;
    int value;
} Node;

Node* get_leftmost_child(Node *);

// return inorder successor of head provided
// case: all the node values are unique in this BST
Node* solution(Node *head) {
    // 1. if head is root
    if (head->parent == nullptr) {
        // if head doesn't have right child
        if (head->right == nullptr) return nullptr;
        // move to right then
        return get_leftmost_child(head->right);
    } else if (head == head->parent->left) { // if head is left child
        // if head doesn't have right child
        if (head->right == nullptr) return head->parent;
        // move to right then
        return get_leftmost_child(head->right);
    } else {  // if head is right child
        // if head doesn't have right child
        int valh = head->value;
        Node *thead = head->parent;
        while (thead != nullptr) {
            if (thead->value > valh) return thead;
            thead = thead->parent;
        }
        if (!thead) return thead;
        return get_leftmost_child(head->right);
    }
}

Node* get_leftmost_child(Node* head) {
    Node *temp = head;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

int main(void) {
    Node *head = nullptr;  // say we got this as input

    return 0;
}
