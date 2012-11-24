#ifndef MY_BST_H
#define MY_BST_H

typedef struct NodeTag {
    int value;
    struct NodeTag *left;
    struct NodeTag *right;
} Node; 

typedef struct {
    Node *root;
} Tree;

extern Tree *create_tree();
extern int insert_value(int value, Tree **tree);
extern int delete_value(int value, Tree **tree);
extern int print_in_order(Node *root);
extern int find_value(int value, Tree **tree);

#endif
