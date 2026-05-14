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
        return;
    }
    in_order_traversal(root->left);
    printf("%d-->",root->value);
    in_order_traversal(root->right);
}

// delete

int search(Node *root, int x)
{
    Node *ptr = root;
    if(root == NULL)
    {
        printf("Value not found in the tree \n");
        return 0;
    }
    
    if (root->value == x)
    {
        printf("Node is in the tree \n");
        return 1;
    }
    if(x > ptr->value)
    {
        return search(ptr->right,x);
    }
    else
    {
        return search(ptr->left,x);
    }
}

void preorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d-->",root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d-->",root->value);

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
    search(n,6);
    preorder_traversal(n);
    printf("\n");
    postorder_traversal(n);
    return 0;
}