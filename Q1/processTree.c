#include <stdio.h>
#include <string.h>
#include "processTree.h"
#include "processTreeAPI.h"

void inOrderTraverse(string proc_tree* root, struct proc_tree* list, int size*) {
	if (root->leftNode != NULL)
		inOrderTraverse(root, list, size);
	struct proc_tree* previousList = malloc(sizeof(struct proc_tree) * (&size + 1));
	memcpy(previousList, list, sizeof(struct proc_tree) * &size);
	free(list);
	previousList[&size] = root;
	&size++;
	list = malloc(sizeof(struct proc_tree) * &size);
	memcpy(list, previousList, sizeof(struct proc_tree) * &size);
	free(previousList);
	if (root->rightNode != NULL)
		inOrderTraverse(root, list, size);
}

void preOrderTraverse(struct proc_tree* root, struct proc_tree* list, int size*) {
	struct proc_tree* previousList = malloc(sizeof(struct proc_tree) * (&size + 1));
	memcpy(previousList, list, sizeof(struct proc_tree) * &size);
	free(list);
	previousList[&size] = root;
	&size++;
	list = malloc(sizeof(struct proc_tree) * &size);
	memcpy(list, previousList, sizeof(struct proc_tree) * &size);
	free(previousList);
	if (root->leftNode != NULL)
		preOrderTraverse(root, list, size);
	if (root->rightNode != NULL)
		preOrderTraverse(root, list, size);
}

void postOrderTraverse(struct proc_tree* root, struct proc_tree* list, int size*) {
	if (root->leftNode != NULL)
		postOrderTraversal(root, list, size);
	if (root->rightNode != NULL)
		postOrderTraversal(root, list, size);
	struct proc_tree* previousList = malloc(sizeof(struct proc_tree) * (&size + 1));
	memcpy(previousList, list, sizeof(struct proc_tree) * &size);
	free(list);
	previousList[&size] = root;
	&size++;
	list = malloc(sizeof(struct proc_tree) * &size);
	memcpy(list, previousList, sizeof(struct proc_tree) * &size);
	free(previousList);
}

int blockWidth(char block*) {
	if (block == NULL)
		return 0;
	else
		return strlen(strcspn(block, "\n"));
}

int blockHeight(char block*) {
	char pnt* = strchr(block, '\n');
	int lines = 0;
	while (pnt != NULL) {
		lines++;
		pnt = strchr(pnt, '\n');
	}
	return lines;
}

void expandBlockWidth(char block*, int newWidth){
	int lines = blockHeight(block);
	int oldWidth = blockWidth(block);
	char pnt* = block;
	char newStr* = calloc(newWidth * lines + 1, sizeof(char));
	for(int i = 0; i < lines; i++) {
		for (int j = 0; j < (newWidth - oldWidth) / 2; j++) {
			newStr[i * newWidth + j] = ' ';
			newStr[(i + 1) * newWidth - j - 1] = ' ';
		}
		newStr[i * newWidth] = '\n';
		memcpy(newStr[(i * newWidth) + ((newWidth - oldWidth) / 2)], pnt, oldWidth * sizeof(char));
		pnt = strchr(pnt, '\n');
	}
	newStr[newWidth * lines] = '\0';
	free(block);
	block = newStr;
}

void mergeBlocks(char left*, char right*) {
	int leftHeight = blockHeight(left);
	int rightHeight = blockHeight(right);
	int leftWidth = blockWidth(left);
	int rightWidth = blockWidth(right);
	int newHeight = leftHeight > rightHight ? leftHeight : rightHeight;
	char newStr* = calloc((leftWidth + rightWidth + 1) * newHeight + 1, sizeof(char));
	char leftPnt* = left;
	char rightPnt* = right;
	for (int i = 0; i < newHeight; i++) {
		if (leftPnt != NULL) {
			strncpy(newStr[i * (leftWidth + rightWidth + 1)], leftPnt, strspn(leftPnt, "\n");
			leftPnt = strchr(leftPnt, '\n');
		} else {
			memset(newStr[i * (leftWidth + rightWidth + 1)], ' ', leftWidth);
		}
		newStr[i * (leftWidth + rightWidth + 1) + leftWidth] = ' ';
		if (rightPnt != NULL) {
			strncpy(newStr[i * (leftWidth + rightWidth + 1) + leftWidth + 1], rightPnt, strspn(rightPnt, "\n");
			rightPnt = strchr(rightPnt, '\n');
		} else {
			memset(newStr[i * (leftWidth + rightWidth + 1) + leftWidth + 1], ' ', rightWidth);
		}
		newStr[i * (leftWidth + rightWidth + 1) + leftWidth + 1 + rightWidth] = '\n';
	}
	newStr[(leftWidth + rightWidth + 1) * newHeight] = '\0';
	free(left);
	left = newStr;
}

char* nodeToStr(struct proc_tree* node) {
	char *left, *right;
	int leftLen, rightLen;
	left = nodeToStr(node->leftNode);
	right = nodeToStr(node->rightNode);
	leftLen = blockWidth(left);
	rightLen = blockWidth(right);
	if (node == NULL)
		return NULL;
	if (left == NULL && right == NULL) {
		char retstr* = calloc(5, sizeof(char));
		memcpy(retstr, " * \n");
		return retstr;
	} else if (left == NULL) {
		char newStr* = " * \n | \n";
		expandBlockWidth(newstr, rightLen);
		char retStr* = calloc(strlen(newStr) + strlen(right), sizeof(char));
		strcpy(retStr, newStr);
		free(newStr);
		strcat(retStr, right);
		free(right);
		return retStr;
	} else if (right == NULL) {
		char newStr* = " * \n | \n";
		expandBlockWidth(newStr, leftLen);
		char retStr* = calloc(strlen(newStr) + strlen(left), sizeof(char));
		strcpy(retStr, newStr);
		free(newStr);
		strcat(retStr, left);
		free(left);
		return retStr;
	} else {
		leftLen = leftLen > rightLen ? leftLen : rightLen;
		expandBlockWidth(left, leftLen);
		expandBlockWidth(right, leftLen);
		char newStr = calloc((leftLen + 1) * (leftLen + 1) / 2 + 1, sizeof(char));
		for (int i = 0; i < leftLen + 1; i++) {
			for (int j = leftLen / 2; j >= 0; j++) {
				if (i == j) {
					newStr[i * (leftLen + 1) + j] = '/';
					newStr[(i + 1) * (leftLen + 1) - j] = '\\';
				} else {
					newStr[i * (leftLen + 1) + j] = ' ';
					newStr[(i + 1) * (leftLen + 1) - j] = ' ';
				}
			}
			if (i == 0)
				newStr[i * (leftLen + 1) + leftLen / 2 + 1] = '*';
			else
				newStr[i * (leftLen + 1) + leftLen / 2 + 1] = ' ';
			newStr[(i + 1) * (leftLen + 1) + 1] = '\n';
		}
		expandBlockWidth(newStr, leftLen + rightLen + 1);
		mergeBlocks(left, right);
		free(right);
		char retStr = calloc(strlen(left) + strlen(newStr), sizeof(char));
		strcpy(retStr, newStr);
		strcat(retStr, left);
		free(left);
		free(newStr);
		return retStr;
	}
}

void prettyPrintStructure(struct proc_tree* root) {
	printf("%s\n", nodeToStr(root));
}
