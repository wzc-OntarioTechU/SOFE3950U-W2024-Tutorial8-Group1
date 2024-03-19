#ifndef processTree_H
#define processTree_H
#include "process.h"
struct proc_tree {
	struct proc process;
	struct proc_tree* leftNode;
	struct proc_tree* rightNode;
};
#endif
