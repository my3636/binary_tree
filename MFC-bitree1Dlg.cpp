
// MFC-bitree1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC-bitree1.h"
#include "MFC-bitree1Dlg.h"
#include "afxdialogex.h"
#include "define1.h"

#include <Windows.h>
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

#define ini_X 10
#define ini_Y 300


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32772();
	afx_msg void On32773();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	//ON_COMMAND(ID_32773, &CAboutDlg::On32773)
END_MESSAGE_MAP()


// CMFCbitree1Dlg 对话框

CMFCbitree1Dlg::CMFCbitree1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCBITREE1_DIALOG, pParent)
	, build_tree(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCbitree1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, build_tree);
	//  DDX_Text(pDX, IDC_bianli, m_bianli);
}

BEGIN_MESSAGE_MAP(CMFCbitree1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCbitree1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_bt_build, &CMFCbitree1Dlg::OnBnClickedbtbuild)
//	ON_STN_CLICKED(IDC_bianli, &CMFCbitree1Dlg::OnStnClickedbianli)
ON_BN_CLICKED(IDC_XXXSH_BUTTON, &CMFCbitree1Dlg::OnBnClickedXxxshButton)
ON_BN_CLICKED(IDC_ZXXSH_BUTTON, &CMFCbitree1Dlg::OnBnClickedZxxshButton)
ON_BN_CLICKED(IDC_HXXSH_BUTTON, &CMFCbitree1Dlg::OnBnClickedHxxshButton)
END_MESSAGE_MAP()


// CMFCbitree1Dlg 消息处理程序

BOOL CMFCbitree1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCbitree1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCbitree1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDC *dc1 = GetDC();
		RECT rcText;
		rcText.left = 60;
		rcText.top = 320;
		rcText.right = 660;
		rcText.bottom = 640;

		dc1->FillSolidRect(&rcText, RGB(255, 255, 255));
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCbitree1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//===================================================================================================//
int nceng = 0;
int xb = 0;
bitree T_build;
//bitree T2, T3;
void iniQ(SqQueue &Q)
{
	Q.base = (QElemType *)malloc(MAXQ * sizeof(QElemType));
	if (!Q.base)exit(-1);
	Q.front = Q.rear = 0;
}
void DestroyQueue(SqQueue &Q)
{
	if (Q.front != NULL)
	{
		free(Q.base);
	}
}
//计算各个结点的横坐标
void c_x(bitree &T)
{
	if (T)
	{
		if (T->lchild)
		{
			T->lchild->pic_x = T->pic_x - (nceng * 10 - T->level * 11);
			c_x(T->lchild);
		}
		if (T->rchild)
		{
			T->rchild->pic_x = T->pic_x + (nceng * 10 - T->level * 11);
			c_x(T->rchild);
		}
	}
}

void CMFCbitree1Dlg::paintree()
{
	// TODO:  在此添加命令处理程序代码
	CDC *dc1 = GetDC();
	CRect rect;
	CPoint point;
	/*GetCursorPos(&point);//获取当前指针的坐标（注意，这是屏幕的） 
	GetWindowRect(&rect);//获取客户区（客户区的左上角）相对于屏幕的位置  
	int _x = (point.x - rect.left);//通过变换的到客户区的坐标  
	int _y = (point.y - rect.top);*/
	CString str;


	RECT rcText;
	rcText.left = 60;
	rcText.top = 320;
	rcText.right = 660;
	rcText.bottom = 640;

	dc1->FillSolidRect(&rcText, RGB(255, 255, 255));

	//InvalidateRect(NULL);

	dc1->SetBkMode(TRANSPARENT);
	dc1->SetTextColor(RGB(0, 0, 0));
/*	str.Format(_T("heihei"));
	dc1->TextOut(10, 300, str);*/


		SqQueue Q;
		bitree p;
		iniQ(Q);
		int now_ceng = 0;
		c_x(T_build);
		if (T_build)
		{
			//if (Q.front == Q.rear)T->level = 0;
			Q.base[Q.rear] = T_build;
			Q.rear = (Q.rear + 1) % MAXQ;
			while (Q.front != Q.rear)
			{
				p = Q.base[Q.front];
				if (p->lchild)
				{
					Q.base[Q.rear] = p->lchild;
					Q.rear = (Q.rear + 1) % MAXQ;
				}
				if (p->rchild)
				{
					Q.base[Q.rear] = p->rchild;
					Q.rear = (Q.rear + 1) % MAXQ;
				}
				if (now_ceng != p->level)
				{
					now_ceng = p->level;
				}
				UpdateData(FALSE);
				dc1->TextOut(p->pic_x * 4 + ini_X, ini_Y + now_ceng * 40, (CString)p->data);
				UpdateData(TRUE);
				//gotoxy(hout, p->pic_x + ini_X, ini_Y + now_ceng * 3);
				//cout << p->data;
				Q.front = (Q.front + 1) % MAXQ;
			}
		}
		DestroyQueue(Q);
}

void CMFCbitree1Dlg::paintree_thr(bitree T)
{
	SqQueue Q;
	bitree p;

	bitnode *kongge;
	kongge = (bitree)malloc(sizeof(bitnode));
	if (!kongge)exit(-1);
	kongge->data = ' ';
	kongge->level = 0;
	kongge->LTag = Thread;
	kongge->RTag = Thread;
	kongge->lchild = kongge;
	kongge->rchild = kongge;

	iniQ(Q);
	bool biaoji[MAXQ] = { Link };
	int now_ceng = 0;
	int huanhang = 1;
	int hangshu = 0;
	int i = 0;
	char p_out[1000];
	int p_xb = 0;
	if (T)
	{
		for (int j = 0; j < pow(2, (nceng - hangshu) + 2) + 1; j++)
		{
			p_out[p_xb] = ' ';
			p_xb++;
		}
			//cout << " ";
		Q.base[Q.rear] = T;
		Q.rear = (Q.rear + 1) % MAXQ;
		while (/*Q.front != Q.rear*/hangshu <= nceng)
		{
			p = Q.base[Q.front];
			if (p->lchild)
			{
				if (p->LTag == Thread)
					biaoji[Q.rear] = Thread;
				if (biaoji[Q.front] == Link)
				{
					Q.base[Q.rear] = p->lchild;
					Q.rear = (Q.rear + 1) % MAXQ;
				}
				else
				{
					Q.base[Q.rear] = kongge;
					Q.rear = (Q.rear + 1) % MAXQ;
				}

			}
			if (p->rchild)
			{
				if (p->RTag == Thread)
					biaoji[Q.rear] = Thread;
				if (biaoji[Q.front] == Link)
				{
					Q.base[Q.rear] = p->rchild;
					Q.rear = (Q.rear + 1) % MAXQ;
				}
				else
				{
					Q.base[Q.rear] = kongge;
					Q.rear = (Q.rear + 1) % MAXQ;
				}
			}
			//cout << p->data;
			p_out[p_xb] = p->data;
			p_xb++;
			if (p->data == ' ')
			{
				p_out[p_xb] = ' ';
				p_xb++;
				p_out[p_xb] = ' ';
				p_xb++;
			}
			else
			{
				p_out[p_xb] = p->LTag + '0';
				p_xb++;
				p_out[p_xb] = p->RTag + '0';
				p_xb++;
			}
			i++;
			if (i == huanhang)
			{
				//cout << endl;
				p_out[p_xb] = '\n\r';
				p_xb++;
				p_out[p_xb] = '\n\r';
				p_xb++;
				hangshu++;
				for (int j = 0; j < pow(2, (nceng - hangshu) + 2) + 3; j++)
				{
					p_out[p_xb] = ' ';
					p_xb++;
				}
					//cout << " ";
				i = 0;
				huanhang = huanhang * 2;
			}
			else
			{
				for (int j = 0; j < (pow(2, (nceng - hangshu + 1) + 2) - 1 - 3); j++)
				{
					p_out[p_xb] = ' ';
					p_xb++;
				}
					//cout << " ";
			}
			Q.front = (Q.front + 1) % MAXQ;
		}
		p_out[p_xb] = '\0';
		p_xb++;
		USES_CONVERSION;
		CString s_shu = A2T(p_out);
		GetDlgItem(IDC_TREE_STATIC)->SetWindowText(s_shu);
	}
	//cout << endl;
}

void createbitree(bitree &T, int  &nleaves, CString ch_cs, int ceng)
{
	int length = ch_cs.GetLength();
	if (length==xb)
	{
		//xiabiao++;
		return;
	}
	if (ch_cs[xb] == '#')
	{
		xb++;
		T = NULL;
	}
	else
	{
		T = (bitree)malloc(sizeof(bitnode));
		if (!T)exit(-1);
		T->data = ch_cs[xb];
		T->level = ceng;
		if (nceng < ceng)nceng = ceng;
		T->LTag = Link;
		T->RTag = Link;
		T->pic_x = 80;
		xb++;
		createbitree(T->lchild, nleaves, ch_cs, ceng + 1);
		createbitree(T->rchild, nleaves, ch_cs, ceng + 1);
		if (T->lchild == NULL&&T->rchild == NULL)
			nleaves++;
	}
}

void preorder(bitree T, char* result)
{
	//static int xb = 0;
	result[xb] = T->data;
	xb++;
	if (T->lchild) preorder(T->lchild, result); 
	if (T->rchild) preorder(T->rchild, result); 
	result[xb] = '\0';
}
void inordertraverse(bitree T, char* result)
{
	//static int xb = 0;
	if (T)
	{
		if (T->lchild)inordertraverse(T->lchild, result);
		result[xb] = T->data;
		xb++;
		if (T->rchild)inordertraverse(T->rchild, result);
	}
	result[xb] = '\0';
}
void PostOrderTraverse(bitree T, char* result)
{
	//static int xb = 0;
	if (T)
	{
		PostOrderTraverse(T->lchild, result);
		PostOrderTraverse(T->rchild, result);
		result[xb] = T->data;
		xb++;
	}
	result[xb] = '\0';
}

/*释放二叉树的内存空间，将二叉树置空*/
void bitreeSetNull(bitnode *&tree)
{
	if (tree == NULL)
	{
		return;
	}
	bitreeSetNull(tree->lchild);
	bitreeSetNull(tree->rchild);
	free(tree);
}

//==================================================================================//

void CopyTree(bitree T, bitree &T1)
{
	if (T)
	{
		T1 = (bitree)malloc(sizeof(bitnode));
		if (!T1)
		{
			//printf("Overflow\n");
			exit(1);
		}
		T1->data = T->data;
		T1->LTag = Link;
		T1->RTag = Link;
		T1->level = T->level;
		T1->pic_x = T->pic_x;
		T1->lchild = T1->rchild = NULL;
		CopyTree(T->lchild, T1->lchild);
		CopyTree(T->rchild, T1->rchild);
	}
}
bitree pre = NULL;
void PreThreading(bitree T)
{
	//static bitree pre = NULL;
	bitree P = T;
	if (P)
	{
		if (!P->lchild)//无左孩子
		{
			P->LTag = Thread; P->lchild = pre;
		}
		if (!P->rchild) P->RTag = Thread;
		if (pre && pre->RTag == Thread) pre->rchild = P;
		pre = P;
		if (P->LTag == Link) PreThreading(P->lchild);
		if (P->RTag == Link) PreThreading(P->rchild);
	}
}

void InThreading2(bitree P) {
	static bitree pre = NULL;
	if (P) {
		InThreading2(P->lchild);
		if (!P->lchild)
		{
			P->LTag = Thread; P->lchild = pre;
		}
		if (!P->rchild) P->RTag = Thread;
		if (pre && pre->RTag == Thread) pre->rchild = P;
		pre = P;
		InThreading2(P->rchild);
	}
}

void PostThreading(bitree P)
{
	static bitree pre = NULL;
	if (P)
	{
		PostThreading(P->lchild);
		PostThreading(P->rchild);
		if (!P->lchild)
		{
			P->LTag = Thread; P->lchild = pre;
		}
		if (!P->rchild) P->RTag = Thread;
		if (pre && pre->RTag == Thread) pre->rchild = P;
		pre = P;
	}
}

void preorder_thr(bitree T)
{
	bitree p = T;
	cout << p->data;
	while (p->rchild)
	{
		if (p->LTag == Link)p = p->lchild;
		else p = p->rchild;
		cout << p->data;
	}
}

void inorder_Thr(bitree T)
{
	bitree p = T;
	while (p->LTag == Link) p = p->lchild;
	cout << p->data;
	while (p->rchild)//只有中序遍历的最后一个结点，它的rchild才会是空
	{
		if (p->RTag == Link)
		{
			p = p->rchild;
			while (p->LTag == Link) p = p->lchild;
		}
		else p = p->rchild;
		cout << p->data;
	}
}


//==================================================================================//
void CMFCbitree1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFCbitree1Dlg::OnBnClickedbtbuild()
{
	// TODO: 在此添加控件通知处理程序代码
	int nleaves = 0;
	//bitree T_build;
	if(T_build)bitreeSetNull(T_build);
	UpdateData(TRUE);
	xb = 0;
	createbitree(T_build, nleaves, build_tree, 1);
	char *result = (char *)malloc(40 * sizeof(char));

	/*先序遍历*/
	xb = 0;
	preorder(T_build, result);
	//CString *pwnd = (CStatic*)GetDlgItem(IDC_bianli); //提取静态文本框句柄
	//SetDlgItemText(IDC_bianli, build_tree);
	USES_CONVERSION;
	CString s_bianli = A2T(result);
	GetDlgItem(IDC_DLR_ANS)->SetWindowText(s_bianli);

	xb = 0;
	inordertraverse(T_build, result);
	s_bianli = A2T(result);
	GetDlgItem(IDC_LDR_ANS)->SetWindowText(s_bianli);

	xb = 0;
	PostOrderTraverse(T_build, result);
	s_bianli = A2T(result);
	GetDlgItem(IDC_LRD_ANS)->SetWindowText(s_bianli);
	
	CString str_leaves;
	str_leaves.Format(_T("%d"), nleaves);
	GetDlgItem(IDC_YEZI_ANS)->SetWindowText(str_leaves);
	
	
	paintree();

	UpdateData(FALSE);
	free(result);
	//bitreeSetNull(T_build);
}

void CMFCbitree1Dlg::OnBnClickedXxxshButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	bitree T1;
	CopyTree(T_build, T1);
	pre = NULL;
	PreThreading(T1);
	paintree_thr(T1);
	//bitreeSetNull(T1);
	char *result = (char *)malloc(40 * sizeof(char));
	xb = 0;
	preorder(T_build, result);
	//CString *pwnd = (CStatic*)GetDlgItem(IDC_bianli); //提取静态文本框句柄
	//SetDlgItemText(IDC_bianli, build_tree);
	USES_CONVERSION;
	CString s_bianli = A2T(result);
	GetDlgItem(IDC_DLR_THR_STATIC)->SetWindowText(s_bianli);
	UpdateData(FALSE);
}
void CMFCbitree1Dlg::OnBnClickedZxxshButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	char *result = (char *)malloc(40 * sizeof(char));
	bitree T2;
	CopyTree(T_build, T2);
	pre = NULL;
	InThreading2(T2);
	paintree_thr(T2);
	//bitreeSetNull(T2);
	/*先序遍历*/


	USES_CONVERSION;
	xb = 0;
	inordertraverse(T_build, result);
	CString s_bianli = A2T(result);
	GetDlgItem(IDC_LDR_THR_STATIC)->SetWindowText(s_bianli);
	UpdateData(FALSE);
}
void CMFCbitree1Dlg::OnBnClickedHxxshButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	bitree T3;
	CopyTree(T_build, T3);
	pre = NULL;
	PostThreading(T3);
	paintree_thr(T3);
	//bitreeSetNull(T3);
	UpdateData(FALSE);
}

