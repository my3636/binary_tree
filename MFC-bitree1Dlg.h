
// MFC-bitree1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include"define1.h"


// CMFCbitree1Dlg �Ի���
class CMFCbitree1Dlg : public CDialogEx
{
// ����
public:
	CMFCbitree1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCBITREE1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
