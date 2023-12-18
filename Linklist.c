#include "Linklist.h"

LinkHead* creatLink() {
	LinkHead* res;
	//�����ͷ
	res = (LinkHead*)malloc(sizeof(LinkHead));
	if (res == NULL) {
		fprintf(stderr, "Link malloc faild!\n");
		return NULL;
	}
	//��ʼ����ͷ
	res->num = 0;
	res->headnode.data = 0x143;	//���ݱ����������
	res->headnode.next = NULL;

	return res;
}

void releaseLink(LinkHead* link) {
	//���ͷ�node,���ͷű�ͷ
}

int Headinsert(LinkHead* head, Element val) {
	Node* pos = &head->headnode;	//ǰ�ڵ�
	//�����½ڵ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		fprintf(stderr, "malloc newnode failde!\n");
		return -1;
	}
	newNode->data = val;
	newNode->next = pos->next;
	pos->next = newNode;
	return 0;
}

int remove(LinkHead* head, Element val) {
	Node* pos = &head->headnode;
	// ��ʽ��������������ģ��
	while (pos->next) {
		if (pos->next->data == val) {
			break;
		}
		pos = pos->next;
	}
	//ɾ�����Ƿ��ҵ�
	if (pos->next) {
		//����
		Node* tmp = pos->next;
		pos->next = tmp->next;
		free(tmp);
	} else {
		printf("No %d element!\n", val);
		return -1;
	}

}

void showHeadLinker(LinkHead* head) {
	Node* pos = head->headnode.next;
	printf("[");
	while (pos) {	
		printf("%d", pos->data);
		if (pos->next != NULL) {
			printf(", ");
		}
		pos = pos->next;
	}
	printf("]");
	printf("\n");
}