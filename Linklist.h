#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Element;

typedef struct _Node{
	Element data;
	struct _Node* next;
}Node;

/*��ͷ���ı�ͷ*/
typedef struct {
	Node headnode;
	int num;
}LinkHead;

/*��ʼ��*/
LinkHead* creatLink();
void releaseLink(LinkHead* link);

/*���ݲ��룺��ǰֱ�ӵ�*/
int Headinsert(LinkHead *head, Element val);
int insert(LinkHead* head, Element val);

/*����ɾ��*/
int remove(LinkHead* head, Element val);

/*�鿴����Ԫ��*/
void showHeadLinker(LinkHead* head);
