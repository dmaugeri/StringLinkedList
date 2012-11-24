#include <stdio.h>
#include <stdlib.h>
#include "MyBst.h"

int main(int argc, char *argv[]) {
    Tree *t = create_tree();
    insert_value(50, &t);
    insert_value(59, &t);
    insert_value(30, &t);
    insert_value(100, &t);
    insert_value(55, &t);
    insert_value(88, &t);
    delete_value(55, &t);
    print_in_order(t->root);
}
