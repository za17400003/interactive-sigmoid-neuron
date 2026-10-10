
// Neurona1Dlg.cpp: archivo de implementación
//

#include "pch.h"
#include "framework.h"
#include "Neurona1.h"
#include "Neurona1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cuadro de diálogo de CNeurona1Dlg



CNeurona1Dlg::CNeurona1Dlg(CWnd* pParent /*= nullptr*/)
	: CDialogEx(IDD_NEURONA1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNeurona1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNeurona1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CNeurona1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CNeurona1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Controladores de mensajes de CNeurona1Dlg

BOOL CNeurona1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Establecer el icono para este cuadro de diálogo.  El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// TODO: agregar aquí inicialización adicional
	total = 0;
	Training = false;
	Drawing = false;
	SetTimer(0, 500, NULL);
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CNeurona1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono.  Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CNeurona1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rect;
		GetClientRect(&rect);
		int Cx = (rect.Width()) / 2;
		int Cy = (rect.Height()) / 2;
		CPaintDC dc(this);

		w = rect.Width();
		h = rect.Height();

		dc.FillSolidRect(0, Cy, rect.Width(), 4, (COLORREF)0x00000000);
		dc.FillSolidRect(Cx, 0, 4, rect.Height(), (COLORREF)0x00000000);

		NN.Draw(dc, rect);

		CDialogEx::OnPaint();
		for (int i = 0; i < total; i++)
		{
			int x0 = db[i][0];
			int y0 = db[i][1];

			if (d[i] == 0.0)
			{
				dc.FillSolidRect(x0, y0 - 2, 8, 8, (COLORREF)0x00000000);
			}
			else
			{
				dc.FillSolidRect(x0, y0 - 2, 8, 8, (COLORREF)0x000000FF);
			}
		}

		if (Drawing) {
			NN.DrawPerfect(dc, rect);
			Drawing = false;
		}

	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CNeurona1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNeurona1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	
	UpdateData(true);
	db[total][0] = point.x;
	db[total][1] = point.y;
	d[total] = 1.0;
	total++;
	UpdateData(false);
	InvalidateRect(NULL);
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CNeurona1Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	UpdateData(true);
	db[total][0] = point.x;
	db[total][1] = point.y;
	d[total] = 0.0;
	total++;
	UpdateData(false);
	InvalidateRect(NULL);
	CDialogEx::OnRButtonUp(nFlags, point);
}


void CNeurona1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	if (Training)
	{
		float te = 0;

		for (int i = 0; i < total; i++) {
			float x = db[i][0];
			float y = db[i][1];
			float de = d[i];

			float kx = 20 / w;
			float ky = 20 / h;

			x = (x - w / 2) * kx;
			y = -(y - h / 2) * ky;

			float e = NN.Train(x, y, de);
			te += e * e;
			
		}
		printf("Error: %f\n", te);
		InvalidateRect(NULL);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CNeurona1Dlg::OnBnClickedButton3()
{
	Training = true;

	// TODO: Agregue aquí su código de controlador de notificación de control
}

void CNeurona1Dlg::OnBnClickedButton2()
{
	Training = false;
	Drawing = true;

	InvalidateRect(NULL);
	// TODO: Agregue aquí su código de controlador de notificación de control
}
