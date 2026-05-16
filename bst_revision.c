#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
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
    Node *t = (Node *) malloc(sizeof(Node));
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    tree->root = insert_node(tree->root, t);
}

Node *insert_node(Node *root, Node *new_node)
{
    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        if(new_node->data > root->data)
        {
            root->right = insert_node(root->right,new_node);
        }
        else
        {
            root->left = insert_node(root->left, new_node);
        }
    }
    return root;
}

// postorder traversal, delete

int search(Node *root, int value)
{
    Node *t;
    t = root;

    if (t == NULL)
    {
        printf("Not found! \n");
        return 0;
    }
    else
    {
        if(t->data == value)
        {
            printf("Value found in the tree! \n");
            return 1;
        }
        else if(value > t->data)
        {
            return search(t->right, value);
        }
        else 
        {
            return search(t->left, value);
        }
    }
}

void in_order_traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_order_traversal(root->left);
    printf("%d --> ",root->data);
    in_order_traversal(root->right);
}

void preorder_traversal(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d -->",root->data);
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
    printf("%d --> ", root->data);
}

void delete(Node **root, int value)
{
    Node *rsbt;
    Node *t = *root;
    Node *previous = *root;
    if (t == NULL)
    {
        printf("Not found\n");
        return;
    }
    else
    {
        if(t->data != value)
        {
            previous = t;
            if (value > t->data)
            {
                return delete(&(t->right), value);
            }
            else
            {
                return delete(&(t->left), value);
            }
        }

        if(t->left == NULL && t->right == NULL)
        {
            if (t == previous)
            {
                *root = NULL;
            }
            if (value > previous->data)
            {
                previous->right = NULL;
            }
            else 
            {
                previous->left = NULL;
            }
            free(t);
        }

        else if(t->left != NULL && t->right == NULL)
        {
            if (previous->data > value)
            {
                previous->left = t->left;
            }
            else
            {
                previous->right = t->left;
            }
            free(t);
        }
        else if(t->left == NULL && t->right != NULL)
        {
            if (previous->data > value)
            {
                previous->left = t->right;
            }
            else 
            {
                previous->right = t->right;
            }
            free(t);
        }
        
        else
        {
            rsbt = t->right;
            if(rsbt->left == NULL)
            {
                if (rsbt->right == NULL)
                {
                    t->data = rsbt->data;
                    t->right = NULL;
                }
                else 
                {
                    t->data = rsbt->data;
                    t->right = rsbt->right;
                    rsbt->right = NULL;
                }
                
                free(rsbt);
            }

            else if(rsbt->left != NULL)
            {
                while(rsbt->left != NULL)
                {
                    previous = rsbt;
                    rsbt = rsbt->left;
                }
                // should delink it from the previous node
                t->data = rsbt->data;
                if (rsbt->right != NULL)
                {
                    previous->left = rsbt->right;
                }
                else
                {
                    previous->left = NULL;
                }
                free(rsbt);
            }
        }

    }
}

int main(void)
{
    BST tree, *ptr;
    tree.root = NULL;
    ptr = &tree;
    insert(&tree, 10);
    insert(&tree, 18);
    insert(&tree, 15);
    insert(&tree, 2);
    insert(&tree, 8);
    insert(&tree, 5);
    insert(&tree, 30);
    in_order_traversal(ptr->root);
    delete(&(ptr->root), 30);
    return 0;
}