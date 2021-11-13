#pragma once
#ifndef _PQUEUE_H
#define _PQUEUE_H

#include "huffman.h"


#define TYPE htNode *

#define MAX_SZ 256
//队列节点
typedef struct _pQueueNode {
	TYPE val;//树
	unsigned int priority;//优先级
	struct _pQueueNode *next;//
}pQueueNode;
//队列
typedef struct _pQueue {
	unsigned int size;//队列长度
	pQueueNode *first;//头指针
}pQueue;//

void initPQueue(pQueue **queue);
void addPQueue(pQueue **queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue **queue);

#endif