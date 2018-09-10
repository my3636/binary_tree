
// MFC-bitree1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include"define1.h"


// CMFCbitree1Dlg 对话框
class CMFCbitree1Dlg : public CDialogEx
{
// 构造
public:
	CMFCbitree1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBITREE1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void paintree();
	afx_msg void paintree_thr(bitree T);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedbtbuild();
	CString build_tree;
//	CString m_bianli;
	afx_msg void OnBnClickedXxxshButton();
	afx_msg void OnBnClickedZxxshButton();
	afx_msg void OnBnClickedHxxshButton();
	afx_msg void OnStnClickedDlrThrStatic();
};
