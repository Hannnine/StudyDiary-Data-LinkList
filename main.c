/*
1.��ʽ�洢�����ƾ�����
	A -> B -> C -> D
	���ݵ���һ���ڵ㣬��������һ���ڵ����Ϣ
2.��ʽ�洢����������
	2.1����
		�����������ԣ�����û�л�ͷ�� ����B�Ҳ���A�ڵ�
		5��λ����Ҫ��4��λ�ò���

	2.2ɾ��

	2.3����

3.ʵ�֣�
	3.1��ͷ�ڵ������

	3.2��ͷָ�������
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