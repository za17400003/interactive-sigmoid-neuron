
// Neurona1Dlg.h: archivo de encabezado
//

#pragma once
#include "Neurona.h"


// Cuadro de diálogo de CNeurona1Dlg
class CNeurona1Dlg : public CDialogEx
{
// Construcción
public:
	CNeurona1Dlg(CWnd* pParent = nullptr);	// Constructor estándar

// Datos del cuadro de diálogo
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEURONA1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	//data base
	float db[100][2];
	float d[100];
	int total;
	bool Training;
	bool Drawing;
	Neurona NN;
	float w, h;

	bool entrenar;
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
