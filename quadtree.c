#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "quadtree.h"

QuadTreeNode *create_node() {
    QuadTreeNode *node = malloc(sizeof(QuadTreeNode));
    node->parent       = NULL;
    for (size_t i = 0; i < 4; i++) {
        node->children[i]    = NULL;
        node->corners[i][0]  = 0.0;
        node->corners[i][1]  = 0.0;
    }
    node->num_data = 0;

    return node;
}

QuadTreeNode *init_tree(float width, float height) {
    QuadTreeNode *root  = create_node();
    root->corners[0][0] = 0.0;
    root->corners[0][1] = 0.0;

    root->corners[1][0] = width;
    root->corners[1][1] = 0.0;

    root->corners[2][0] = width;
    root->corners[2][1] = height;

    root->corners[3][0] = 0.0;
    root->corners[3][1] = height;
    return root;
}

void assign_children_corners(QuadTreeNode *parent) {
    QuadTreeNode *ulChild  = parent->children[0];
    ulChild->corners[0][0] = parent->corners[0][0];
    ulChild->corners[0][1] = parent->corners[0][1];
    ulChild->corners[1][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    ulChild->corners[1][1] = parent->corners[1][1];
    ulChild->corners[2][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    ulChild->corners[2][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;
    ulChild->corners[3][0] = parent->corners[0][0];
    ulChild->corners[3][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;

    QuadTreeNode *urChild  = parent->children[1];
    urChild->corners[0][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    urChild->corners[0][1] = parent->corners[0][1];
    urChild->corners[1][0] = parent->corners[1][0];
    urChild->corners[1][1] = parent->corners[1][1];
    urChild->corners[2][0] = parent->corners[2][0];
    urChild->corners[2][1] = (parent->corners[1][1] + parent->corners[2][1]) / 2;
    urChild->corners[3][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    urChild->corners[3][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;

    QuadTreeNode *brChild  = parent->children[2];
    brChild->corners[0][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    brChild->corners[0][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;
    brChild->corners[1][0] = parent->corners[1][0];
    brChild->corners[1][1] = (parent->corners[1][1] + parent->corners[2][1]) / 2;
    brChild->corners[2][0] = parent->corners[2][0];
    brChild->corners[2][1] = parent->corners[2][1];
    brChild->corners[3][0] = (parent->corners[3][0] + parent->corners[2][0]) / 2;
    brChild->corners[3][1] = parent->corners[3][1];

    QuadTreeNode *blChild  = parent->children[3];
    blChild->corners[0][0] = parent->corners[0][0];
    blChild->corners[0][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;
    blChild->corners[1][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    blChild->corners[1][1] = (parent->corners[0][1] + parent->corners[3][1]) / 2;
    blChild->corners[2][0] = (parent->corners[0][0] + parent->corners[1][0]) / 2;
    blChild->corners[2][1] = parent->corners[2][1];
    blChild->corners[3][0] = parent->corners[3][0];
    blChild->corners[3][1] = parent->corners[3][1];

    return;
}

void print_corners(QuadTreeNode *node) {
    printf("   Upper  Left  (x, y) = (%f, %f)\n", node->corners[0][0], node->corners[0][1]);
    printf("   Upper  Right (x, y) = (%f, %f)\n", node->corners[1][0], node->corners[1][1]);
    printf("   Bottom Right (x, y) = (%f, %f)\n", node->corners[2][0], node->corners[2][1]);
    printf("   Bottom Left  (x, y) = (%f, %f)\n", node->corners[3][0], node->corners[3][1]);
    return;
}

void print_children(QuadTreeNode *node) {
    printf("-------------------------------------------\n");
    printf("PARENT NODE:\n");
    print_corners(node);
    if (!node->children[0]) {
        printf("THIS NODE DOES NOT HAVE ANY CHILDREN\n");
    }
    else {
        printf("CHILDREN NODES:\n");
        for (int i = 0; i < 4; i++) {
            if (i == 0) printf("Upper Left Child:\n");
            if (i == 1) printf("Upper Right Child:\n");
            if (i == 2) printf("Bottom Right Child:\n");
            if (i == 3) printf("Bottom Left Child:\n");
            print_corners(node->children[i]);
        }
    }
    printf("-------------------------------------------\n");
    return;
}

void split_node(QuadTreeNode *node) {
    if (node->num_data < 20) {
        return;
    }

    QuadTreeNode *ulChild = create_node();
    ulChild->parent = node;
    node->children[0] = ulChild;

    QuadTreeNode *urChild = create_node();
    urChild->parent = node;
    node->children[1] = urChild;

    QuadTreeNode *brChild = create_node();
    brChild->parent = node;
    node->children[2] = brChild;

    QuadTreeNode *blChild = create_node();
    blChild->parent = node;
    node->children[3] = blChild;

    assign_children_corners(node);

    return;
}

void count_data_points(QuadTreeNode *root, float) {

    return;
}

int main() {
    QuadTreeNode *root = init_tree(2.0, 2.0);
    // split_node(root);
    print_children(root);
    return 0;
}
