#ifndef QUADTREE_H
#define QUADTREE_H

#include <stdint.h>

#ifndef THRESHOLD_H
#define THRESHOLD_H 20
#endif

typedef struct quadtreenode{
    struct quadtreenode *parent;
    struct quadtreenode *children[4];   // Upper Left, Upper Right, Bottom Right, Bottom Left
    float               corners[4][2];  // Upper Left, Upper Right, Bottom Right, Bottom Left
    uint16_t            num_data;
} QuadTreeNode;

typedef struct {
    size_t len;  // 8 bytes
    float  points[][2];
} DataPoints;

QuadTreeNode *create_node();                                                 // Returns a default node with paren NULL, all children NULL, all corner 0, and num_data 0.
QuadTreeNode *init_tree(float width, float height);                          // Returns the root. A tree can be represented only by its root.
void         assign_children_corners(QuadTreeNode *parent);                  // Calculates the positions of children's corners.
void         print_corners(QuadTreeNode *node);                              // Prints a node's corners
void         print_children(QuadTreeNode *node);                             // Prints a node's children
void         split_node(QuadTreeNode *node);                                 // Creates children nodes for a node that has more than THRESHOLD_H data points. (actually insert())
void         count_data_points(QuadTreeNode *root, DataPoints data_points);  // TODO Count for all, but ignore leaf nodes (check children[0])
void         update(QuadTreeNode *root);                                     // split_node() over all leaf nodes.

#endif
