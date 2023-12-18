#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct _Node{
	Element data;
	struct _Node* next;
}Node;

/*带头结点的表头*/
typedef struct {
	Node headnode;
	int num;
}LinkHead;

/*初始化*/
LinkHead* creatLink();
void releaseLink(LinkHead* link);

/*数据插入：找前直接点*/
int Headinsert(LinkHead *head, Element val);
int insert(LinkHead* head, Element val);

/*数据删除*/
int remove(LinkHead* head, Element val);

/*查看链表元素*/
void showHeadLinker(LinkHead* head);
