#ifndef processTreeAPI_H
#define processTreeAPI_H
#include "processTree.h"
// traversals return an array of pointers to the nodes, the size integer pointer
// is used to output the size of the resultant array
struct proc_tree* inOrderTraverse(struct proc_tree* root, int size*);

struct proc_tree* preOrderTraverse(struct proc_tree* root, int size*);

struct proc_tree* postOderTraverse(struct proc_tree* root, int size*);

// print tree structure, without the info the node. For visualization only.
void prettyPrintStructure(struct proc_tree* root);
#endif
