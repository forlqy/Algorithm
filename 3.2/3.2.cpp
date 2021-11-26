//(a)单向链表
//beforeP is the cell before the two adjacent cells that are to be swapped  beforeP是要交换的两个相邻单元格之前的单元格
//error checks are omitted for clarity
void swapWithNext(Node* beforep) {
	Node* p, * afterp;

	p = before->next;
	afterp = p->next;//both p and afterp assumed not NULL 假定不为空

	p->next = afterp->next;
	beforep->next = afterp;
	afterp->next = p;
}

//(b)双向链表

void swapWithNext(Node* beforep) {
	Node* beforep, * afterp;

	p->next = afterp->next;
	beforep->next = afterp;
	afterp->next = p;
	p->next->prev = p;
	p->prev = afterp;
	afterp->prev = beforep;
}