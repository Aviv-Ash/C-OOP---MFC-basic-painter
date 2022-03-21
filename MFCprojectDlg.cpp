
// MFCprojectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCprojectDlg dialog



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	/*, MWidth(0)*/
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
//	CDialogEx::DoDataExchange(pDX);
//	/*DDX_Text(pDX, IDC_EDIT1, MWidth);*/
//	/*DDV_MinMaxInt(pDX, MWidth, 1, 8);*/
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCprojectDlg::OnBnClickedCancel)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &CMFCprojectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CMFCprojectDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO3, &CMFCprojectDlg::OnBnClickedRadio3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_RADIO4, &CMFCprojectDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CMFCprojectDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CMFCprojectDlg::OnBnClickedRadio6)
END_MESSAGE_MAP()


// CMFCprojectDlg message handlers

BOOL CMFCprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO3, IDC_RADIO3);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCprojectDlg::OnPaint()
{
	if (IsIconic())
	{
	}
	else
	{
		CPaintDC dc(this); 
		for (int i = 0; i < shapes.GetSize(); i++) {
			shapes[i]->Draw(&dc);
		}

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCprojectDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	start = point;
	ispreesed = true;


	if ((shapes.GetSize()) > 0 && (movepreesed || changesize)) {

		for (int i = shapes.GetSize() - 1; i >= 0; i--)
		{
			if (shapes[i]->isInside(point))
			{
				moveindex = i;
				break;
			}
		}

	}
	else {
		switch (FutureShapeKind)
		{
		case 1:
			shapes.Add(new Line(start, start));
			break;
		case 2:
			shapes.Add(new RectangleS(start, start));
			break;
		case 3:
			shapes.Add(new EllipseS(start, start));
			break;
		case 4:
			shapes.Add(new TriangleS(start, start));
			break;
		}
	}



	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	if (!changesize && !movepreesed) {
		end = point;
		shapes[shapes.GetSize() - 1]->Redefine(start, end);
		Invalidate();
	}
	ispreesed = false;
	changesize = false;
	movepreesed = false;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point)
{

	if (ispreesed) {
		if ((shapes.GetSize()) > 0 && movepreesed) {
			shapes[moveindex]->mEnd.x += (point.x - shapes[moveindex]->mStart.x);
			shapes[moveindex]->mEnd.y += (point.y - shapes[moveindex]->mStart.y);
			shapes[moveindex]->mStart.x = point.x;
			shapes[moveindex]->mStart.y = point.y;
			Invalidate();
		}
		else if ((shapes.GetSize()) > 0 && changesize) {
			shapes[moveindex]->mStart.x = point.x;
			shapes[moveindex]->mStart.y = point.y;
			Invalidate();
		}
		else {
			CClientDC dc(this);
			dc.SetROP2(R2_XORPEN);//NOT
			shapes[shapes.GetSize() - 1]->Draw(&dc);
			end = point;
			shapes[shapes.GetSize() - 1]->Redefine(start, end);
			shapes[shapes.GetSize() - 1]->Draw(&dc);
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedRadio1()//rectangle radio button
{
	FutureShapeKind = 2;
	// TODO: Add your control notification handler code here
}


void CMFCprojectDlg::OnBnClickedRadio2()//ellipse radio button
{
	FutureShapeKind = 3;
	// TODO: Add your control notification handler code here
}


void CMFCprojectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(FALSE, _T(".shps"), NULL, 0, _T("Shapes (*.shps)|*.shps|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CMFCprojectDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".shps"), NULL, 0, _T("Shapes (*.shps)|*.shps|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		for (int i = shapes.GetSize() - 1; i >= 0; i--) {
			delete shapes[i];
		}
		shapes.RemoveAll();
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CMFCprojectDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, _T(".shps"), NULL, 0, _T("Shapes (*.shps)|*.shps|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		CTypedPtrArray<CObArray, Shape*>savedshapes;
		savedshapes.Serialize(ar);
		shapes.Append(savedshapes);
		ar.Close();
		file.Close();
		Invalidate();
	}
}







void CMFCprojectDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	FutureShapeKind = 1;
}







void CMFCprojectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	for (int i = shapes.GetSize() - 1; i >= 0; i--) {
		if (shapes[i]->isInside(point)) {
			shapes.RemoveAt((INT_PTR)i, 1);
			Invalidate();
			break;
		}
	}

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFCprojectDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	shapes.RemoveAll();
	Invalidate();
}





void CMFCprojectDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	changesize = true;
	
}


void CMFCprojectDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	movepreesed = true;

}


void CMFCprojectDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	FutureShapeKind = 4;
}


