#ifndef _Queue_H
#define _Queue_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue
{
	int a[10]; //���г���
	int last;  //��β
	int first; //����
} Queue;

int IsEmpty(Queue queue);
int IQueue(Queue *queue, int data);
int OQueue(Queue *queue);


#endif
