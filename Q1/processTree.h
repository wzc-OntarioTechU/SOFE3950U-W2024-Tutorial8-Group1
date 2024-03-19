#ifndef process_H
#include "process.h"
#endif
#ifndef processTree_H
#define processTree_H
struct proc_tree {
	struct proc process;
	struct proc_tree* leftNode;
	struct proc_tree* rightNode;
};
#endif
