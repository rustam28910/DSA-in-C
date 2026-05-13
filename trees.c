#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct BST
{
    Node *root;
}BST;

Node *insert_node(Node *root, Node *new_node);

void insert(BST *tree, int value)
{
    Node *t;
    t = (Node *) malloc(sizeof(Node));
    t->value = value;
    t->right = NULL;
    t->left = NULL;
    tree->root = insert_node(tree->root, t);
}

Node * insert_node(Node *root, Node * new_node)
{
    if (root == NULL)
    {
        return new_node;
    }
    if (new_node->value < root->value)
    {
        if (root->left != NULL)
        {
            root->left = insert_node(root->left, new_node);
        }
        else
        {
            root->left = new_node;
        }
    }

    else
    {
        if (new_node->value > root->value)
        {
            if(root->right != NULL)
            {
                root->right = insert_node(root->right, new_node);
            }
            else
            {
                root->right = new_node;
            }
        }
    }

    return root;
}

void in_order_traversal(Node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty \n");
        return;
    }
    in_order_traversal(root->left);
    printf("%d-->",root->value);
    in_order_traversal(root->right);
}

int main(void)
{
    BST tree;
    tree.root = NULL;
    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 20);
    insert(&tree, 25);
    insert(&tree, 18);
    insert(&tree, 4);
    insert(&tree, 6);
    BST *p = &tree;
    Node *n = p->root;
    in_order_traversal(n);
    return 0;
}