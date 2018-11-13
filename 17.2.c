#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void bst_add(TreeNode *root, int val) {
    if (root) {
        if (root->val < val) {
            if (root->right) {
                bst_add(root->right, val);
            }
            else {
                root->right = malloc(sizeof(TreeNode));
                memset(root->right, 0, sizeof(TreeNode));
                root->right->val = val;
            }
        }
        else {
            if (root->left) {
                bst_add(root->left, val);
            }
            else {
                root->left = malloc(sizeof(TreeNode));
                memset(root->left, 0, sizeof(TreeNode));
                root->left->val = val;
            }
        }
    }
}

TreeNode *to_linked_list(TreeNode *root, TreeNode **head, TreeNode *prev) {
    if (root) {
        TreeNode *prev_left = to_linked_list(root->left, head, prev);

        if (prev_left) {
            prev = prev_left;
        }

        if (prev) {
            prev->right = root;
        }
        else {
            *head = root;
        }

        root->left = prev;
        TreeNode *prev_right = to_linked_list(root->right, head, root);

        if (prev_right) {
            return prev_right;
        }
    }

    return root;
}

int main() {
    int i;
    int tree[] = {2, 1, 4, 3, 6, 7, 8};

    TreeNode *prev;
    TreeNode *head;
    TreeNode *root = malloc(sizeof(*root));
    memset(root, 0, sizeof(*root));
    root->val = 5;

    for (i = 0; i < 7; i++) {
        bst_add(root, tree[i]);
    }

    to_linked_list(root, &head, NULL);

    while (head) {
        printf("%d->", head->val);
        prev = head;
        head = head->right;
        free(prev);
    }

    puts("");
    return 0;
}
