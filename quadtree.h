#ifndef QUADTREE_H
#define QUADTREE_H

#include <stdint.h>

#ifndef THRESHOLD_H
#define THRESHOLD_H 20
#endif

typedef struct {
    struct QuadTreeNode *parent;
    struct QuadTreeNode *children[4];   // Upper Left, Upper Right, Bottom Right, Bottom Left
    uint16_t            corners[4][2];  // Upper Left, Upper Right, Bottom Right, Bottom Left
    uint16_t            num_data;
} QuadTreeNode;

QuadTreeNode *create_node();                         // Returns a default node with paren NULL, all children NULL, all corner 0, and num_data 20.
QuadTreeNode *init_tree(int16_t width, int height);  // Returns the root. A tree can be represented only by its root.
void         split_node(QuadTreeNode *node);         // Creates children nodes for a node that has more than THRESHOLD_H data points. (actually insert())
void         count_data_points();                    // TODO Count for all, but ignore leaf nodes (check children[0])

#endif
