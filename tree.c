
#include <stdio.h>
#include <stdlib.h>

// Step 1: Define the structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Step 2: Create a new node
struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Step 3: Preorder Traversal (Root, Left, Right)
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

// Step 4: Inorder Traversal (Left, Root, Right)
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

// Step 5: Postorder Traversal (Left, Right, Root)
void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}

// Step 6: Main function
int main()
{
    struct Node *root;

    // Create the binary tree
    root = createNode(10);

    root->left = createNode(20);

    root->right = createNode(30);

    // Display traversals
    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
