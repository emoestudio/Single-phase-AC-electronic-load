/*
 * queue.c
 *
 *  Created on: Jul 14, 2022
 *      Author: EVA
 */

#include <eva_queue.h>
#include<stdio.h>
#include<stdlib.h>

//创建循环队列
SqQueue initQueue(){
	SqQueue *sq=(SqQueue *)malloc(sizeof(SqQueue));
//	if(sq ==NULL){
//		return;
//	}
	sq->rear=sq->front=0;
	return *sq;
}
//判断循环队列是否为空
int isEmpty(SqQueue qu){
	return (qu.front ==qu.rear?1:0);
}
//元素进循环队列
int enQueue(SqQueue *qu,int x){
	if((qu->rear+1)%maxsize ==qu->front){
		deQueue(qu);
	}
	qu->data[qu->rear]=x;
	qu->rear=(qu->rear+1)%maxsize;
	return 1;
}
//元素出循环队列
int deQueue(SqQueue *qu){
	if(qu->rear ==qu->front){
		return 0;
	}
//	*y=qu->data[qu->front];
	qu->front=(qu->front+1)%maxsize;
	return 1;
}
//打印循环队列
int printQueue(SqQueue qu){
	if(qu.rear ==qu.front){
		return 0;
	}
	while(qu.rear !=qu.front){
		qu.front=(qu.front+1)%maxsize;
		printf("当前队列值=%d\n",qu.data[qu.front]);
	}
	return 1;
}
//void main(){
//	int y=0;
//	SqQueue sq =initQueue();
//	enQueue(&sq,1);
//	enQueue(&sq,2);
//	enQueue(&sq,3);
//	enQueue(&sq,4);
//	deQueue(&sq,&y);
//	printQueue(sq);
//	printf("当前的front=%d\n",sq.front);
//	printf("当前的rear=%d\n",sq.rear);
//
//}
