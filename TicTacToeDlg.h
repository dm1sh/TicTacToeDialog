#pragma once

#include <afxwin.h>

#include "TicTacToeGame.h"
#include "resource.h"

class CTicTacToeDlg : public CDialog, public TicTacToeGame {
public:
	CTicTacToeDlg() : CDialog(IDD_TIC_TAC_TOE_DIALOG) {};

private:
	void OnOK();
	void DoDataExchange(CDataExchange* pDX);

	CButton buttons[9];

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedSquare(UINT nID);
};
