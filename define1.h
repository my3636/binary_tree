#pragma once
#pragma once
#include<iostream>
using namespace std;
#define MAXN 10000
#define MAXQ 7000

#define Link 0 //孩子
#define Thread 1 //线索

typedef struct bitnode {
	wchar_t data;
	int level;
	int pic_x;
	int RTag, LTag;//=1为孩子，=0为前驱/后继
	bitnode *lchild, *rchild;
}bitnode, *bitree;
typedef bitnode *QElemType;
typedef struct {
	QElemType *base;
	int front, rear;
}SqQueue;

//bitree T_build;
//int xb = 0;

/*建立一棵二叉树, 并求叶子节点个数*/
void createbitree(bitree &T, int &, CString ch_cs, int ceng);
/*先序遍历二叉树*/
void preorder(bitree T, char *result);
/*中序遍历二叉树*/
void inordertraverse(bitree T, char *result);
/*后序遍历二叉树*/
void PostOrderTraverse(bitree T, char* result);
/*复制二叉树*/
void CopyTree(bitree T, bitree &T1);
/*先序线索化二叉树*/
void PreThreading(bitree P);
/*中序线索化二叉树*/
void InThreading2(bitree P);
/*后序线索化二叉树*/
void PostThreading(bitree P);
/*遍历先序线索二叉树*/
void preorder_thr(bitree T);
/*遍历中序线索二叉树*/
void inorder_Thr(bitree T);
/*销毁二叉树*/
void bitreeSetNull(bitnode *&tree);

/*创建队列*/
void iniQ(SqQueue &Q);
/*销毁队列*/
void DestroyQueue(SqQueue &Q);

/*计算输出树形结构时，每个节点的横坐标x*/
void c_x(bitree &T);