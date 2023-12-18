#include "Linklist.h"

LinkHead* creatLink() {
	LinkHead* res;
	//申请表头
	res = (LinkHead*)malloc(sizeof(LinkHead));
	if (res == NULL) {
		fprintf(stderr, "Link malloc faild!\n");
		return NULL;
	}
	//初始化表头
	res->num = 0;
	res->headnode.data = 0x143;	//根据表的物理属性
	res->headnode.next = NULL;

	return res;
}

void releasesLink(LinkHead* link) {
	//先释放node,再释放表头
	if (link) {
		Node* pos = &link->headnode;
		if (link->headnode.next) {
			//释放所有
			while (pos->next) {
				Node* tmp = pos->next;
				pos->next = tmp->next;
				free(tmp);
				--link->num;
			}
			printf("%d linknodes left!\n", link->num);
		}
	}
}

int Headinsert(LinkHead* head, Element val) {
	Node* pos = &head->headnode;	//前节点
	//申请新节点
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		fprintf(stderr, "malloc newnode failde!\n");
		return -1;
	}
	newNode->data = val;
	newNode->next = pos->next;
	pos->next = newNode;
	++head->num;
	return 0;
}

int remove(LinkHead* head, Element val) {
	Node* pos = &head->headnode;
	// 链式遍历符合条件的模版
	while (pos->next) {
		if (pos->next->data == val) {
			break;
		}
		pos = pos->next;
	}
	//删除：是否找到
	if (pos->next) {
		//备份
		Node* tmp = pos->next;
		pos->next = tmp->next;
		free(tmp);
		--head->num;
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

int insertval(LinkHead* head, Element pos, Element val) {
	Node* pt = &head->headnode;
	while (pt->next) {
		if (pt->next->data == pos) {
			break;
		}
		pt = pt->next;
	}

	if (pt->next) {
		Node* tmp = (Node*)malloc(sizeof(Node));
		if (!tmp) {
			fprintf(stderr, "Failed to allocate memory for new node\n");
			return -1;
		}
		tmp->data = val;
		tmp->next = pt->next;
		pt->next = tmp;
		head->num++;
	} else {
		printf("No %d element!\n", pos);
		return -1;
	}
}

int insertnum(LinkHead* head, Element pos, Element val) {
	Node* pt = &head->headnode;
	int index = -1;

	if (pos < 0 || pos > head->num) {
		printf("Invalid input!\n");
		return -1;
	}

	while (index < pos-1) {
		pt = pt->next;
		++index;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = val;
	tmp->next = pt->next;
	pt->next = tmp;
	head->num++;
}
