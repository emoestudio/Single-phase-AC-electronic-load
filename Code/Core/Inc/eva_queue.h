/*
 * queue.h
 *
 *  Created on: Jul 14, 2022
 *      Author: EVA
 */

#ifndef INC_EVA_QUEUE_H_
#define INC_EVA_QUEUE_H_

#include <eva_paremeters.h>


#define maxsize 1000


typedef struct SqQueue{
	int data[maxsize];
	int front;//队首指针
	int rear;//队尾指针
}SqQueue;

SqQueue initQueue();
int isEmpty(SqQueue qu);
int enQueue(SqQueue *qu,int x);
int deQueue(SqQueue *qu);
int printQueue(SqQueue qu);

#endif /* INC_EVA_QUEUE_H_ */
