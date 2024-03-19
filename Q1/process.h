#ifndef process_H
#define process_H
struct proc {
	char parent[256];
	char name[256];
	int priority;
	int memory;
};
#endif
