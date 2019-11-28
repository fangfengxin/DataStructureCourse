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
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10

typedef struct LNode{	//��������ʽ�ṹ���Ķ���
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
int listinit = 0;	//���Ա��ʼ��״̬
void main(void) {
	LinkList L = NULL;
	status res;	//���������ֵ
	int op = 1;	//������
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
		printf("      ��ѡ����Ĳ���[0~12]:");
		scanf_s("%d", &op);
		switch (op) {
		case 1:
			//printf("\n----IntiList���ܴ�ʵ�֣�\n");
			res = InitList(L);
			if (res == OK)
				printf("���Ա����ɹ���\n");
			else if (res == INFEASTABLE)
				printf("���Ա��Ѵ��ڣ����贴����\n");
			else
				printf("���Ա���ʧ�ܣ�\n");
			getchar(); getchar();
			break;
		case 2:
			//printf("\n----DestroyList���ܴ�ʵ�֣�\n");
			res = DestroyList(L);
			if (res == OK)
				printf("���Ա����ٳɹ���\n");
			else
				printf("���Ա����ڣ��������٣�\n");
			getchar(); getchar();
			break;
		case 3:
			//printf("\n----ClearList���ܴ�ʵ�֣�\n");
			res = ClearList(L);
			if (res == OK)
				printf("���Ա���ճɹ���\n");
			else
				printf("���Ա����ڣ�������գ�\n");
			getchar(); getchar();
			break;
		case 4:
			//printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
			res = ListEmpty(L);
			if (res == TRUE)
				printf("���Ա��ǿձ�\n");
			else if (res == FALSE)
				printf("���Ա��ǿձ�\n");
			else
				printf("���Ա����ڣ�\n");
			getchar(); getchar();
			break;
		case 5:
			//printf("\n----ListLength���ܴ�ʵ�֣�\n");
			res = ListLength(L);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else
				printf("���Ա�ĳ���Ϊ%d��\n", res);
			getchar(); getchar();
			break;
		case 6:
			//printf("\n----GetElem���ܴ�ʵ�֣�\n");
			printf("�����ȡ���Ա�ĵڼ���Ԫ�أ�");
			scanf_s("%d", &loc);
			res = GetElem(L, loc, e);
			if (res == OK)
				printf("��Ԫ��Ϊ%d", e);
			else if (res == ERROR)
				printf("����λ�ó������Ա�Χ��\n");
			else
				printf("���Ա����ڣ�\n");
			getchar(); getchar();
			break;
		case 7:
			//printf("\n----LocateElem���ܴ�ʵ�֣�\n");
			printf("��������ĸ�Ԫ�أ�");
			scanf_s("%d", &e);
			res = LocateElem(L, e);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else if (res == ERROR)
				printf("����λ�ó������Ա�Χ��\n");
			else
				printf("%dΪ���Ա�ĵ�%d��Ԫ��", e, res);
			getchar(); getchar();
			break;
		case 8:
			//printf("\n----PriorElem���ܴ�ʵ�֣�\n");
			printf("��������ĸ�Ԫ�ص�ǰ����");
			scanf_s("%d", &e);
			res = PriorElem(L, e, pre_e);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else if (res == ERROR)
				printf("����ʧ�ܣ���Ԫ�ز������Ա��л򲻴���ǰ��)\n");
			else
				printf("%d��ǰ����%d", e, pre_e);
			getchar(); getchar();
			break;
		case 9:
			//printf("\n----NextElem���ܴ�ʵ�֣�\n");
			printf("��������ĸ�Ԫ�صĺ�̣�");
			scanf_s("%d", &e);
			res = PriorElem(L, e, next_e);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else if (res == ERROR)
				printf("����ʧ�ܣ���Ԫ�ز������Ա��л򲻴��ں��)\n");
			else
				printf("%d�ĺ����%d", e, next_e);
			getchar(); getchar();
			break;
		case 10:
			//printf("\n----ListInsert���ܴ�ʵ�֣�\n");
			printf("�������Ԫ�ص�λ�ã�");
			scanf_s("%d", &loc);
			printf("��������Ԫ�أ�");
			scanf_s("%d", &e);
			res = ListInsert(L, loc, e);
			if (res == OVERFLOW)
				printf("���Ա�����ڴ�ʧ�ܣ�Ԫ���޷����룡\n");
			else if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else if (res == ERROR)
				printf("����λ�ó������Ա�Χ��\n");
			else
				printf("����ɹ���\n");
			getchar(); getchar();
			break;
		case 11:
			//printf("\n----ListDelete���ܴ�ʵ�֣�\n");
			printf("����ɾ��Ԫ�ص�λ�ã�");
			scanf_s("%d", &loc);
			res = ListDelete(L, loc, e);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
			else if (res == ERROR)
				printf("ɾ��λ�ó������Ա�Χ��\n");
			else
				printf("ɾ���ɹ���ɾ����Ԫ����%d��\n", e);
			getchar(); getchar();
			break;
		case 12:
			//printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
			res == ListTrabverse(L);
			if (res == INFEASTABLE)
				printf("���Ա����ڣ�\n");
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
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
	printf("\n      ������Ѱʲô�ȽϹ�ϵ��\n");
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