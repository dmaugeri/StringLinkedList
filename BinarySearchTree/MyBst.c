#include "MyBst.h"
#include <stdio.h>
#include <stdlib.h>
/*
 *Allocates memory for a new node and returns the pointer
 *to it
 */
static Node *new_node(int data) {
    Node *new = malloc(sizeof(Node));
    new->value = data; 
    new->left = NULL;
    new->right = NULL;
    return new;
}
/*
 * Recursive function that checks for where the Node
 * should be inserted depending on the value of the Node
 */
static int insert_node(Node *n, Node **root) {
    if (n == NULL) //checks if a new node has been created
        return 1;

    if (root == NULL)
        return 1;
    else if (*root == NULL)
        *root = n;
    else if (n->value < (*root)->value) 
        return insert_node(n, &(*root)->left);
    else
        return insert_node(n, &(*root)->right);

    return 0;
}

static Node **find_min(Node **root) {

    if (*root == NULL)
        return root;
    if ((*root)->left == NULL) 
        return &(*root); 

    return find_min(&(*root)->left);
}

/*
 * Find's a node that corresponds with the value being passed and from
 * a certain root node
 */
static Node *find_node(int value, Node **root) {
    if (*root == NULL)
        return NULL;

    if ((*root)->value == value) {
        return *root;
    } 

    if (value < (*root)->value) 
        return find_node(value, &(*root)->left);
    else if (value > (*root)->value)
        return find_node(value, &(*root)->right); 

    return NULL;
}

//delete does not work properly yet
static int delete_node(Node **node) {
    if (node == NULL)
        return 1;
    if (*node == NULL)
        return 1;

    
    if ((*node)->left == NULL && (*node)->right == NULL) {
        free(*node);
        *node = NULL;
    }

    return 0;
}
/*
 * Returns true if a node exists with a certain value
 */
int find_value(int value, Tree **tree) {

    if (find_node(value, &(*tree)->root) != NULL)
        return 1;
    else
        return 0;
}

/*
 * Deletes a node depending on it's value
 * 
 * Does not work quite correctly yet
 */
int delete_value(int value, Tree **tree) {
    if (tree == NULL)
        return 1;

    if (*tree == NULL)
        return 1;

    Node *test= find_node(value, &(*tree)->root);
    delete_node(&test);
    return 0;
}

/*
 * Allocates memory for a new tree
 */
Tree *create_tree() {
    Tree *tree = malloc(sizeof(Tree));
    return tree;
}

/* Adds a root node to tree if tree does not have a root Node
 * creates a new node with the value specified and calls the insert_node
 * function to insert the new node inside the tree
 */
int insert_value(int value, Tree **tree) {
    if (tree == NULL) // checks if tree has been 'created' return error if not created
        return 1;
    if ((*tree) == NULL) {
        Node *new = new_node(value);
        (*tree)->root = new;
    }
    else {
        insert_node(new_node(value), &(*tree)->root);
    }
    return 0;
}

/*
 * Prints from the root node in order
 */
int print_in_order(Node *root) {
    if (root == NULL) {
        return 1;
    }
    print_in_order(root->left);
    printf("%4d\n",root->value);
    print_in_order(root->right);

    return 0;
}
