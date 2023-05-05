#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return;
    }

    if (root->left == NULL) {
        root->left = newNode(data);
    } else if (root->right == NULL) {
        root->right = newNode(data);
    } else {
        insert(root->left, data);
    }
}

Node* insertBST(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int height(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(Node* root) {
    if (root == NULL) {
        return 1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right)) {
        return 1;
    }

    return 0;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

int minValue(Node* root) {
    Node* current = root;

    while (current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

int maxValue(Node* root) {
    Node* current = root;

    while (current->right != NULL) {
        current = current->right;
    }

    return current->data;
}


Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }

    return root;
}


int main() {
    Node* root = newNode(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    int data = 10;
    Node* result = search(root, data);
    if (result != NULL)
        printf("Encontrado: %d\n", result->data);
    else
        printf("Nao encontrado: %d\n", data);
    printf("\n");

    return 0;
}
