#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 300

int main() {
	struct proc_tree root* = NULL;
	FILE fd* = fopen("processes_tree.txt", "r");
	char line[BUFFER_SIZE];
	fgets(line, BUFFER_SIZE, fd);
	while (line != null) {
		struct proc newProc* = malloc(sizeof(struct proc));
		strcpy(newProc->parent, strtoc(line, ", "));
		strcpy(newProc->name, strtoc(NULL, ", "));
		newProc->priority = atoi(strtoc(NULL, ", "));
		newProc->memory = atoi(strtoc(NULL, ", "));
		if (root == NULL) {
			root = malloc(sizeof(struct proc_tree));
			root->process = newProc;
		} else {
			struct proc_tree procArr* = NULL;
			int size* = malloc(sizeof(int));
			&size = 0;
			inOrderTraverse(root, procArr, size);
			for (int i = &size - 1; i >= 0; i--) {
				if (strcmp(procArr[i]->proccess->name, newProc->parent) == 0) {
					if (procArr[i]->leftNode == NULL)
						procArr[i]->leftNode = newProc;
					else if (procArr[i]->rightNode == NULL)
						procArr[i]->rightNode = newProc;
					break;
				}
			}
		}
	}
	fclose(fd);
	printf("Process Tree Structure:\n");
	prettyPrintStructure(root);
	struct proc_tree procArr* = NULL;
	int size* = malloc(sizeof(int));
	&size = 0;
	inOrderTraverse(root, procArr, size);
	printf("\nIn order traversal of tree:\n");
	for (int i = 0; i < &size; i++) {
		printf("Process (%d):\n", &size);
		printf("Parent name: %s\n", procArr[i]->process->parent);
		printf("Process name: %s\n", procArr[i]->process->name);
		printf("Priority: %d\n", procArr[i]->process->priority);
		printf("Memory: %d\n\n", procArr[i]->process->memory);
	}
	procArr* = NULL;
	&size = 0;
	preOrderTraverse(root, procArr, size);
	printf("\nPre-order traversal of tree:\n");
	for (int i = 0; i < &size; i++) {
		printf("Process (%d):\n", &size);
		printf("Parent name: %s\n", procArr[i]->process->parent);
		printf("Process name: %s\n", procArr[i]->process->name);
		printf("Priority: %d\n", procArr[i]->process->priority);
		printf("Memory: %d\n\n", procArr[i]->process->memory);
	}
	procArr* = NULL;
	&size = 0;
	postOrderTraverse(root, procArr, size);
	printf("\nPost-order traversal of tree:\n");
	for (int i = 0; i < &size; i++) {
		printf("Process (%d):\n", &size);
		printf("Parent name: %s\n", procArr[i]->process->parent);
		printf("Process name: %s\n", procArr[i]->process->name);
		printf("Priority: %d\n", procArr[i]->process->priority);
		printf("Memory: %d\n\n", procArr[i]->process->memory);
	}
	return 0;
}
