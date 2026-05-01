#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "quadtree.h"

QuadTreeNode *create_node() {
    QuadTreeNode *node = (QuadTreeNode *) malloc(sizeof(QuadTreeNode));
    node->parent       = NULL;
    for (size_t i = 0; i < 4; i++) {
        root->children[i] = NULL;
        root->corners[i]  = 0;
    }
    root->num_data = 20;

    return node;
}

QuadTreeNode *init_tree(int16_t width, int16_t height) {
    QuadTreeNode *root  = create_node();
    for (size_t i = 0; i < 4; i++) {
        root->corners[i] = {}
    }
    return root;
}

void split_node(QuadTreeNode *node) {
    if (node->num_data < 20) {
        return 0;
    }

    for (size_t i = 0; i < 4; i++) {
        node->children[i] = init_tree()
    }

    return 0;
}

int main() {
    QuadTreeNode *root = init_tree();
    printf("THRESHOLD_H: %d\n", THRESHOLD_H);
    return 0;
}
