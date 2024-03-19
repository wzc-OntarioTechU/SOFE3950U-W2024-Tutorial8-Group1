#ifndef processTree_H
#include "processTree.h"
#endif
#ifndef processTreeAPI_H
#define processTreeAPI_H
// traversals take a pointer to the root node, an array of output, and a pointer of size of output
void inOrderTraverse(struct proc_tree* root, struct proc_tree* list, int size*);

void preOrderTraverse(struct proc_tree* root, struct proc_tree* list, int size*);

void postOderTraverse(struct proc_tree* root, struct proc_tree* list, int size*);

// print tree structure, without the info the node. For visualization only.
void prettyPrintStructure(struct proc_tree* root);
#endif
