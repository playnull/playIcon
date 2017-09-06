
// playIconDlg.h : ͷ�ļ�
//

#pragma once
#include <math.h>
#include "afxwin.h"

// CplayIconDlg �Ի���
class CplayIconDlg : public CDialogEx
{
// ����
public:
	CplayIconDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PLAYICON_DIALOG };

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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

	void SetDeskIcon();
	afx_msg void OnBnClickedCancel();
	CEdit m_iconEdit;
};