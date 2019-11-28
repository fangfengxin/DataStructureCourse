#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct LNode{	//单链表（链式结构）的定义
	ElemType val;
	LNode* next;
}*LinkList;

/*-----page 19 on textbook ---------*/
status InitList(LinkList &L);
status DestroyList(LinkList& L);
status ClearList(LinkList& L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType& e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType cur, ElemType& pre_e);
status NextElem(LinkList L, ElemType cur, ElemType& next_e);
status ListInsert(LinkList& L, int i, ElemType e);
status ListDelete(LinkList& L, int i, ElemType& e);
status ListTrabverse(LinkList L);

/*--------------------------------------------*/
int listinit = 0;	//线性表初始化状态
void main(void) {
	LinkList L = NULL;
	status res;	//各项函数返回值
	int op = 1;	//操作数
	int loc;
	ElemType e, pre_e, next_e;
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       8. PriorElem\n");
		printf("    	  2. DestroyList    9. NextElem\n");
		printf("    	  3. ClearList      10. ListInsert\n");
		printf("    	  4. ListEmpty      11. ListDelete\n");
		printf("    	  5. ListLength     12. ListTrabverse\n");
		printf("    	  6. GetElem        13. ListRead\n");
		printf("    	  7. LocateElem     14. ListSave\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("      请选择你的操作[0~12]:");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiList功能待实现！\n");
			res = InitList(L);
			if (res == OK)
				printf("线性表创建成功！\n");
			else if (res == INFEASTABLE)
				printf("线性表已存在，不需创建！\n");
			else
				printf("线性表创建失败！\n");
			getchar(); getchar();
			break;
		case 2:
			//printf("\n----DestroyList功能待实现！\n");
			res = DestroyList(L);
			if (res == OK)
				printf("线性表销毁成功！\n");
			else
				printf("线性表不存在，不需销毁！\n");
			getchar(); getchar();
			break;
		case 3:
			//printf("\n----ClearList功能待实现！\n");
			res = ClearList(L);
			if (res == OK)
				printf("线性表清空成功！\n");
			else
				printf("线性表不存在，不需清空！\n");
			getchar(); getchar();
			break;
		case 4:
			//printf("\n----ListEmpty功能待实现！\n");
			res = ListEmpty(L);
			if (res == TRUE)
				printf("线性表是空表！\n");
			else if (res == FALSE)
				printf("线性表不是空表！\n");
			else
				printf("线性表不存在！\n");
			getchar(); getchar();
			break;
		case 5:
			//printf("\n----ListLength功能待实现！\n");
			res = ListLength(L);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else
				printf("线性表的长度为%d！\n", res);
			getchar(); getchar();
			break;
		case 6:
			//printf("\n----GetElem功能待实现！\n");
			printf("您想获取线性表的第几个元素？");
			scanf_s("%d", &loc);
			res = GetElem(L, loc, e);
			if (res == OK)
				printf("该元素为%d", e);
			else if (res == ERROR)
				printf("输入位置超出线性表范围！\n");
			else
				printf("线性表不存在！\n");
			getchar(); getchar();
			break;
		case 7:
			//printf("\n----LocateElem功能待实现！\n");
			printf("您想查找哪个元素？");
			scanf_s("%d", &e);
			res = LocateElem(L, e);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else if (res == ERROR)
				printf("输入位置超出线性表范围！\n");
			else
				printf("%d为线性表的第%d个元素", e, res);
			getchar(); getchar();
			break;
		case 8:
			//printf("\n----PriorElem功能待实现！\n");
			printf("您想查找哪个元素的前驱？");
			scanf_s("%d", &e);
			res = PriorElem(L, e, pre_e);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else if (res == ERROR)
				printf("操作失败（该元素不在线性表中或不存在前驱)\n");
			else
				printf("%d的前驱是%d", e, pre_e);
			getchar(); getchar();
			break;
		case 9:
			//printf("\n----NextElem功能待实现！\n");
			printf("您想查找哪个元素的后继？");
			scanf_s("%d", &e);
			res = PriorElem(L, e, next_e);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else if (res == ERROR)
				printf("操作失败（该元素不在线性表中或不存在后继)\n");
			else
				printf("%d的后继是%d", e, next_e);
			getchar(); getchar();
			break;
		case 10:
			//printf("\n----ListInsert功能待实现！\n");
			printf("您想插入元素的位置？");
			scanf_s("%d", &loc);
			printf("您想插入的元素？");
			scanf_s("%d", &e);
			res = ListInsert(L, loc, e);
			if (res == OVERFLOW)
				printf("线性表分配内存失败，元素无法插入！\n");
			else if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else if (res == ERROR)
				printf("输入位置超出线性表范围！\n");
			else
				printf("插入成功！\n");
			getchar(); getchar();
			break;
		case 11:
			//printf("\n----ListDelete功能待实现！\n");
			printf("您想删除元素的位置？");
			scanf_s("%d", &loc);
			res = ListDelete(L, loc, e);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			else if (res == ERROR)
				printf("删除位置超出线性表范围！\n");
			else
				printf("删除成功！删除的元素是%d！\n", e);
			getchar(); getchar();
			break;
		case 12:
			//printf("\n----ListTrabverse功能待实现！\n");
			res == ListTrabverse(L);
			if (res == INFEASTABLE)
				printf("线性表不存在！\n");
			getchar(); getchar();
			break;
		case 13:
			break;
		case 14:
			break;
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()

/*--------page 23 on textbook --------------------*/
status InitList(LinkList& L) {
	if (listinit)
		return INFEASTABLE;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	if (!L)
		return OVERFLOW;
	listinit = 1;
	return OK;
}

status DestroyList(LinkList& L) {
	if (!listinit)
		return INFEASTABLE;
	free(L);
	listinit = 0;
	return OK;
}

status ClearList(LinkList& L) {
	if (!listinit)
		return INFEASTABLE;
	LinkList p = L->next, q;
	L->next = NULL;
	while (p) {
		q = p->next;
		free(p);
	}
	return OK;
}

status ListEmpty(LinkList L) {
	if (!listinit)
		return INFEASTABLE;
	if (!L->next)
		return TRUE;
	return FALSE;
}

int ListLength(LinkList L) {
	if (!listinit)
		return INFEASTABLE;
	LinkList p = L->next;
	int length = 0;
	while (p) { 
		p = p->next;
		length++;
	}
	return length;
}

status GetElem(LinkList L, int i, ElemType& e) {
	if (!listinit)
		return INFEASTABLE;
	int loc = 1, length = ListLength(L);
	if (i < 1 || i > length)
		return ERROR;
	LinkList p = L->next;
	while (loc < i) {
		p = p->next;
	}
	e = p->val;
	return OK;
}

int compare() {
	printf("\n      您想找寻什么比较关系？\n");
	printf("    	  1. >\n");
	printf("    	  2. =\n");
	printf("    	  3. =\n");
	int x;
	scanf_s("%d", &x);
	return x;
}

status LocateElem(LinkList L, ElemType e) {
	if (!listinit)
		return INFEASTABLE;
	int loc = 1;
	int length = ListLength(L);
	int comp = compare();
	LinkList p = L->next;
	switch (comp) {
	case 1:
		while (loc <= length && p->val <= e) {
			p = p->next;
			loc++;
		}
		break;
	case 2:
		while (loc <= length && p->val != e) {
			p = p->next;
			loc++;
		}
		break;
	case 3:
		while (loc <= length && p->val >= e) {
			p = p->next;
			loc++;
		}
		break;
	}
	if (loc <= length)
		return loc;
	return ERROR;
}

status PriorElem(LinkList L, ElemType cur, ElemType& pre_e) {
	if (!listinit)
		return INFEASTABLE;
	if (ListLength(L) < 2 || L->next->val == cur)
		return ERROR;
	LinkList p = NULL, q = L->next;
	while (q->val != cur && q->next != NULL) {
		p = q;
		q = q->next;
	}
	if (p->val == cur) {
		pre_e = p->val;
		return OK;
	}
	return ERROR;
}

status NextElem(LinkList L, ElemType cur, ElemType& next_e) {
	if (!listinit)
		return INFEASTABLE;
	if (ListLength(L) < 2)
		return ERROR;
	LinkList p = L->next;
	while (p && p->val != cur) {
		p = p->next;
	}
	if (p->next) {
		next_e = p->next->val;
		return OK;
	}
	return ERROR;
}

status ListInsert(LinkList& L, int i, ElemType e) {
	if (!listinit)
		return INFEASTABLE;
	if (i < 1 || i > ListLength(L) + 1)
		return ERROR;
	int loc = 0;
	LinkList p = L, q = NULL;
	while (loc < i) {
		q = p;
		q = q->next;
		loc++;
	}
	LinkList newNode = (LinkList)malloc(sizeof(LNode));
	newNode->val = e;
	newNode->next = q;
	p->next = newNode;
	return OK;
}

status ListDelete(LinkList& L, int i, ElemType& e) {
	if (!listinit)
		return INFEASTABLE;
	if (i < 1 || i > ListLength(L))
		return ERROR;
	LinkList p = L, q = NULL;
	int loc = 0;
	while (loc < i) {
		p = q;
		q = q->next;
	}
	e = q->val;
	p->next = q->next;
	free(q);
	return OK;
}

status ListTrabverse(LinkList L) {
	if (!listinit)
		return INFEASTABLE;
	printf("\n-----------all elements -----------------------\n");
	LinkList p = L->next;
	while (p) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}

status ListRead(LinkList& L) {

}