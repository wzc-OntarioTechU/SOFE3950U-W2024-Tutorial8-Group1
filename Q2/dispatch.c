#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MEMORY 1024

struct  {
	char name[256];
	int priority;
	int pid;
	int address;
	int memory;
	int runtime;
	bool suspended;
} proc;

proc popPriority() {

}

void pushPriority(proc p) {

}

proc popSecondary() {

}

void pushSecondary(proc p) {

}

//reads from input file and creates list of processes then pushes them into their respective queues
proc* read() { 
	FILE *file = fopen("processes_q2.txt", "r");
    	if (!file) {
        	perror("Failed to open file");
        	return NULL;
   	}

    	char line[256];

	while (fgets(line, sizeof(line), file)) {
        	tempCount++;
    	}

    	Proc *p = (Proc *)malloc(tempCount * sizeof(Proc));
    	if (!p) {
        	fclose(file);
        	return NULL; // Failed to allocate memory.
    	}

    	fseek(file, 0, SEEK_SET);
   	int i = 0;
   	int priCount;
   	int secCount;
    	while (fgets(line, sizeof(line), file)) {
    		sscanf(line, "%s, %d, %d, %d, %d, %d, %d",
    			&p[i].name, 
    			&p[i].priority,
    			&p[i].pid,
    			&p[i].address,
    			&p[i].memory,
    			&p[i].runtime,
    			&p[i].suspended);
    		if (&p[i].priority == 0) {
    			pushPriority(&p);
    		} else {
    			pushSecondary(&p);
    		}
    		i++;
    	}
}    	

int main(void) {



}
