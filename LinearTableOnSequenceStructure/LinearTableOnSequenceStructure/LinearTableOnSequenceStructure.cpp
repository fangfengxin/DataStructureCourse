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
typedef struct {  //˳���˳��ṹ���Ķ���
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
status LocateElem(SqList L, ElemType e); //�򻯹�
status PriorElem(SqList L, ElemType cur, ElemType& pre_e);
status NextElem(SqList L, ElemType cur, ElemType& next_e);
status ListInsert(SqList& L, int i, ElemType e);
status ListDelete(SqList& L, int i, ElemType& e);
status ListTrabverse(SqList L);	//�򻯹�

/*--------------------------------------------*/
int listinit = 0;	//���Ա��ʼ��״̬
void main(void) {
	SqList L;
	status res;	//���������ֵ
	int op = 1;	//������
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
		case 0:
			break;
		}//end of switch
	}//end of while
	printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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

status LocateElem(SqList L, ElemType e) { //�򻯹�
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
	ElemType* q = &L.elem[i - 1];	//�洢��i��Ԫ�ص�λ��
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