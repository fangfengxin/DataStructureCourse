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
typedef struct {  //顺序表（顺序结构）的定义
	ElemType* elem;
	int length;
	int listsize;
}SqList;

/*-----page 19 on textbook ---------*/
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList& L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i, ElemType& e);
status LocateElem(SqList L, ElemType e); //简化过
status PriorElem(SqList L, ElemType cur, ElemType& pre_e);
status NextElem(SqList L, ElemType cur, ElemType& next_e);
status ListInsert(SqList& L, int i, ElemType e);
status ListDelete(SqList& L, int i, ElemType& e);
status ListTrabverse(SqList L);	//简化过

/*--------------------------------------------*/
int listinit = 0;	//线性表初始化状态
void main(void) {
	SqList L;
	status res;	//各项函数返回值
	int op = 1;	//操作数
	int loc;
	ElemType e, pre_e, next_e;
	while (op) {
		system("cls");	printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList       7. LocateElem\n");
		printf("    	  2. DestroyList    8. PriorElem\n");
		printf("    	  3. ClearList      9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength    11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
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
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("欢迎下次再使用本系统！\n");
}//end of main()

/*--------page 23 on textbook --------------------*/
status InitList(SqList& L) {
	if (listinit)
		return INFEASTABLE;
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		return OVERFLOW;
	listinit = 1;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList& L) {
	if (!listinit)
		return INFEASTABLE;
	free(L.elem);
	listinit = 0;
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}

status ClearList(SqList& L) {
	if (!listinit)
		return INFEASTABLE;
	L.length = 0;
	return OK;
}

status ListEmpty(SqList L) {
	if (!listinit)
		return INFEASTABLE;
	if (!L.length)
		return TRUE;
	return FALSE;
}

int ListLength(SqList L) {
	if (!listinit)
		return INFEASTABLE;
	return L.length;
}

status GetElem(SqList L, int i, ElemType& e) {
	if (!listinit)
		return INFEASTABLE;
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}

status LocateElem(SqList L, ElemType e) { //简化过
	if (!listinit)
		return INFEASTABLE;
	int loc = 0;
	while (loc < L.length && L.elem[loc++] != e);
	if (loc < L.length)
		return loc + 1;
	return ERROR;
}

status PriorElem(SqList L, ElemType cur, ElemType& pre_e) {
	if (!listinit)
		return INFEASTABLE;
	if (*L.elem == cur)
		return ERROR;
	ElemType* p = NULL, * q = L.elem;
	while (*q != cur && q <= &L.elem[L.length - 1])
		p = q++;
	if (q <= &L.elem[L.length] - 1) {
		pre_e = *p;
		return OK;
	}
	return ERROR;
}

status NextElem(SqList L, ElemType cur, ElemType& next_e) {
	if (!listinit)
		return INFEASTABLE;
	if (L.elem[L.length - 1] == cur)
		return ERROR;
	ElemType* p = &L.elem[L.length - 1], * q = NULL;
	while (*p != cur && p >= L.elem)
		q = p--;
	if (p >= L.elem) {
		next_e = *q;
		return OK;
	}
	return ERROR;
}

status ListInsert(SqList& L, int i, ElemType e) {
	if (!listinit)
		return INFEASTABLE;
	if (i < 1 || i > L.length + 1)
		return ERROR;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			return OVERFLOW;
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType* q = &L.elem[i - 1];	//存储第i个元素的位置
	for (ElemType* p = &L.elem[L.length - 1]; p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	L.length++;
	return OK;
}

status ListDelete(SqList& L, int i, ElemType& e) {
	if (!listinit)
		return INFEASTABLE;
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	for (ElemType* p = &L.elem[i - 1]; p < &L.elem[L.length - 1]; p++)
		*p = *(p + 1);
	L.length--;
	return OK;
}

status ListTrabverse(SqList L) {
	if (!listinit)
		return INFEASTABLE;
	int i;
	printf("\n-----------all elements -----------------------\n");
	for (i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
	printf("\n------------------ end ------------------------\n");
	return L.length;
}