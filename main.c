/*
1.链式存储：类似君臣制
	A -> B -> C -> D
	数据当做一个节点，检点包含下一个节点的信息
2.链式存储基本操作：
	2.1插入
		单向链表特性：开弓没有回头箭 如上B找不回A节点
		5号位置需要在4号位置操作

	2.2删除

	2.3查找

3.实现：
	3.1带头节点的链表：

	3.2带头指针的链表：
*/
#include "Linklist.h"

int main() {
	LinkHead* linker = creatLink();
	if (linker == NULL) {
		return -1;
	}

	for (int i = 0; i < 5; ++i) {
		Headinsert(linker, i + 100);
	}

	remove(linker, 103);
	showHeadLinker(linker);

	return 0;
}