
// playIconDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "playIcon.h"
#include "playIconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CplayIconDlg �Ի���




CplayIconDlg::CplayIconDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CplayIconDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CplayIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ICONLIST, m_iconEdit);
}

BEGIN_MESSAGE_MAP(CplayIconDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CplayIconDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CplayIconDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CplayIconDlg ��Ϣ�������

BOOL CplayIconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CplayIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CplayIconDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CplayIconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CplayIconDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT_ICONLIST,"����ץ��ס�ĵ�");
//	SetDeskIcon();

//	CDialogEx::OnOK();
}

void CplayIconDlg::SetDeskIcon()
{
	HWND  hwndParent = ::FindWindow( "Progman", "Program Manager" ); 
	HWND  hwndSHELLDLL_DefView = ::FindWindowEx( hwndParent, NULL, "SHELLDLL_DefView", NULL ); 
	HWND  hwndSysListView32 = ::FindWindowEx( hwndSHELLDLL_DefView, NULL, "SysListView32", "FolderView" );

	int Nm = ListView_GetItemCount( hwndSysListView32 );

	int sNm = 360/Nm;

 	int x = 0,y = 0;
 	int speedx = 30;
 	int speedy = 30;
	int i = 0;
	while(true)
	{
		x += speedx;
		y += speedy;
		if (x > 1920+1920-50/2)
			speedx = -30;
		if (x < 0)
			speedx = 30;
		if (y > 1080-50/2)
			speedy = -30;
		if (y < 0)
			speedy = 30;

		if(i < Nm)
			i++;
		else
			i = 0;

		::SendMessage( hwndSysListView32,   LVM_SETITEMPOSITION, i,   MAKELPARAM( x,y));
		ListView_RedrawItems(hwndSysListView32, i, i + 1);
//		ListView_RedrawItems(hwndSysListView32, 0, ListView_GetItemCount(hwndSysListView32) - 1);
		::UpdateWindow(hwndSysListView32);
		Sleep(50);
	}
// 	while(true)
// 	{
// 		for( int i = 0; i < Nm; i++ )
// 		{
// 			int j = i;
// 			int x = 0;
// 			int y = 0;
// 			while(j--)
// 			{
// 				x += speedx;
// 				y += speedy;
// 				if (x > 1920-50/2)
// 					speedx = -5;
// 				if (x < 0)
// 					speedx = 5;
// 				if (y > 1080-50/2)
// 					speedy = -5;
// 				if (y < 0)
// 					speedy = 5;
// 			}
// 			//int x = 850 + 800*cos( i*sNm*3.1415926/180 );
// 			//int y = 500 + 450*sin( i*sNm*3.1415926/180 );
// 
// 			::SendMessage( hwndSysListView32,   LVM_SETITEMPOSITION, i,   MAKELPARAM( x,y));
// 		}
// 		ListView_RedrawItems(hwndSysListView32, 0, ListView_GetItemCount(hwndSysListView32) - 1);
// 		::UpdateWindow(hwndSysListView32);
// 		Sleep(500);
// 	}
 	
}

UINT wndMove(LPVOID _P)
{
	CWnd* pwnd = (CWnd*)_P;
	int x,y,width,hight;
	CRect rect;
	pwnd->GetWindowRect(rect);
	x = rect.CenterPoint().x;
	y = rect.CenterPoint().y;
	width = rect.Width();
	if(width > 1920/4)
		width = 1920/4;
	hight = rect.Height();
	if(hight > 1080/4)
		hight = 1080/4;
	int speedx = 5;
	int speedy = 5;
	while(true)
	{
		x += speedx;
		y += speedy;
		if (x > 1920+1920-width/2)
			speedx = -5;
		if (x < 0)
			speedx = 5;
		if (y > 1080-hight/2)
			speedy = -5;
		if (y < 0)
			speedy = 5;

		pwnd->MoveWindow(x,y,width,hight);
		Sleep(5);
	}
	return 0;
}

void CplayIconDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
