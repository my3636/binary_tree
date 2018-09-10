#pragma once
#pragma once
#include<iostream>
using namespace std;
#define MAXN 10000
#define MAXQ 7000

#define Link 0 //����
#define Thread 1 //����

typedef struct bitnode {
	wchar_t data;
	int level;
	int pic_x;
	int RTag, LTag;//=1Ϊ���ӣ�=0Ϊǰ��/���
	bitnode *lchild, *rchild;
}bitnode, *bitree;
typedef bitnode *QElemType;
typedef struct {
	QElemType *base;
	int front, rear;
}SqQueue;

//bitree T_build;
//int xb = 0;

/*����һ�ö�����, ����Ҷ�ӽڵ����*/
void createbitree(bitree &T, int &, CString ch_cs, int ceng);
/*�������������*/
void preorder(bitree T, char *result);
/*�������������*/
void inordertraverse(bitree T, char *result);
/*�������������*/
void PostOrderTraverse(bitree T, char* result);
/*���ƶ�����*/
void CopyTree(bitree T, bitree &T1);
/*����������������*/
void PreThreading(bitree P);
/*����������������*/
void InThreading2(bitree P);
/*����������������*/
void PostThreading(bitree P);
/*������������������*/
void preorder_thr(bitree T);
/*������������������*/
void inorder_Thr(bitree T);
/*���ٶ�����*/
void bitreeSetNull(bitnode *&tree);

/*��������*/
void iniQ(SqQueue &Q);
/*���ٶ���*/
void DestroyQueue(SqQueue &Q);

/*����������νṹʱ��ÿ���ڵ�ĺ�����x*/
void c_x(bitree &T);