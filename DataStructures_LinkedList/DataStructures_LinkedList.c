#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct nodeData {
	int value;
	struct nodeData* lastNode;
	struct nodeData* nextNode;
} node;

node* newNode(void) {
	node* newNode = malloc(sizeof(node));
	return newNode;
}

int main(void) {
	node* node1 = newNode();
	node1->value=0;
	node1->lastNode=node1; //head
	node* node2 = newNode();
	node1->nextNode=node2;
	free(node1);
	free(node2);
	return 0;
}
