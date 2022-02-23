#include "TicTacToeApp.h"

#include "TicTacToeDlg.h"

CTicTacToeApp app;

BOOL CTicTacToeApp::InitInstance()
{
	CTicTacToeDlg* dlg = new CTicTacToeDlg();
	m_pMainWnd = dlg;

	dlg->DoModal();

	return TRUE;
}
