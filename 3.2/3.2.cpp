//(a)��������
//beforeP is the cell before the two adjacent cells that are to be swapped  beforeP��Ҫ�������������ڵ�Ԫ��֮ǰ�ĵ�Ԫ��
//error checks are omitted for clarity
void swapWithNext(Node* beforep) {
	Node* p, * afterp;

	p = before->next;
	afterp = p->next;//both p and afterp assumed not NULL �ٶ���Ϊ��

	p->next = afterp->next;
	beforep->next = afterp;
	afterp->next = p;
}

//(b)˫������

void swapWithNext(Node* beforep) {
	Node* beforep, * afterp;

	p->next = afterp->next;
	beforep->next = afterp;
	afterp->next = p;
	p->next->prev = p;
	p->prev = afterp;
	afterp->prev = beforep;
}